from flask import Flask, render_template, request
from cs50 import SQL

app = Flask(__name__)

# read db
db = SQL("sqlite:///forshims.db")

# empty dictionary
REGISTRANTS = {}

# available sports
SPORTS = ["Soccer", "Basketball", "Ultimate Frisbee"]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    if not name or sport not in SPORTS:
        return render_template("error.html")
    REGISTRANTS[name] = sport
    # make data persistent
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

    # return render_template("success.html", name=name, sport=sport)
    return redirect("/registrants")

@app.route("/registrants")
    # function and variable should not use the same name!!!
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)