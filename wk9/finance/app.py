import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    uid = session['user_id']
    rows = db.execute("SELECT * FROM users WHERE id = ?", uid)
    userinfo = rows[0]
    balance = db.execute("SELECT symbol, balance FROM user_balance WHERE user = ?", uid)
    balance_with_current_values = [{**item, "current_value": round(lookup(item["symbol"])["price"] * item["balance"], 2)} for item in balance]
    total_stock_value = sum([item["current_value"] for item in balance_with_current_values])
    return render_template("index.html", userinfo=userinfo, balance=balance_with_current_values, total_stock_value=total_stock_value)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        uid = session['user_id']
        rows = db.execute("SELECT * FROM users WHERE id = ?", uid)
        cash = rows[0]['cash']

        if not symbol or not shares:
            return apology("Symbol and shares must not be blank.", 400)
        if not lookup(symbol):
            return apology("Symbol doesn't exist.", 400)
        if isinstance(shares, str) and if not float(shares):
            return apology("Shares must be integer.", 400)
        if float(shares).is_integer() and float(shares) <= 0:
            return apology("Shares must be greater than 0 and not fractional.", 400)

        unit_price = lookup(symbol)['price']
        shares = int(shares)
        print(unit_price)
        if shares * unit_price > cash:
            return apology("You don't have enough cash", 400)
        db.execute("INSERT INTO transactions (user, symbol, shares, unit_price, total_price) VALUES(?, ?, ?, ?, ?)", uid, symbol, shares, unit_price, -round(unit_price * shares, 2))
        current_balance = db.execute("SELECT balance FROM user_balance WHERE user = ? AND symbol = ?", uid, symbol)
        if not current_balance:
            db.execute("INSERT INTO user_balance (user, symbol, balance) VALUES(?, ?, ?)", uid, symbol, shares)
        else:
            new_balance = round(current_balance[0]['balance'] + shares, 2)
            db.execute("UPDATE user_balance SET balance = ROUND(?, 2) WHERE user = ? AND symbol = ?", new_balance, uid, symbol)
        new_cash = round(cash - unit_price * shares, 2)
        db.execute("UPDATE users SET cash = ROUND(?, 2) WHERE id = ?", new_cash, uid)
        return redirect("/history")
    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    uid = session['user_id']
    rows = db.execute("SELECT * FROM transactions WHERE user = ? ORDER BY created_at DESC", uid)
    return render_template("history.html", rows=rows)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    symbol = request.form.get("symbol")
    results = lookup(symbol)
    if not results or not symbol:
        return apology("Symbol doesn't exist.", 400)
    return render_template("quoted.html", results=results)



@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == 'GET':
        return render_template("register.html")
    username = request.form.get("username")
    password = request.form.get("password")
    password_confirm = request.form.get("confirmation")
    if not username or not password or not password_confirm:
        return apology("must provide username and password", 400)
    if username and password != password_confirm:
        return apology("Passwords given are not matched.", 400)
    is_user_existing = db.execute("SELECT id FROM users WHERE username = ?", username)
    if not is_user_existing:
        hash = generate_password_hash(password)
        id = db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, hash)
        print("user created with id: ", id)
        return redirect("/login")
    return apology("username already exists", 400)

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    uid = session['user_id']
    balance = db.execute("SELECT * FROM user_balance WHERE user = ?", uid)
    """Sell shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))

        # Check if the symbol exists first
        symbol_exists = next(filter(lambda item: item['symbol'] == symbol, balance))

        if symbol_exists:
            # If the symbol exists, check if the balance (shares) is enough
            new_balance = symbol_exists['balance'] - shares
            if new_balance < 0:
                return apology("You don't have enough shares.", 403)
            else:
                # make a transaction to sell
                unit_price = lookup(symbol)['price']
                profit = round(unit_price * shares, 2)
                db.execute("INSERT INTO transactions (user, symbol, shares, unit_price, total_price) VALUES(?, ?, ?, ?, ?)", uid, symbol, -shares, unit_price, profit)
                db.execute("UPDATE user_balance SET balance = ? WHERE user = ? AND symbol = ?", new_balance, uid, symbol)
                db.execute("UPDATE users SET cash = ROUND(cash + ?, 2) WHERE id = ?", profit, uid)
        else:
            print("Symbol does not exist in the list.")
        print("sell something")
        return redirect("/")
    return render_template("sell.html", balance=balance)
