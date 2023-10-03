from flask import Flask, render_template, request

app = Flask(__name__)

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
    if not name:
        return render_template("error.html")
    if sport not in SPORTS:
        return render_template("error.html")
    REGISTRANTS[name] = sport
    return render_template("success.html", name=name, sport=sport)

@app.route("/registrants")
    # function and variable should not use the same name!!!
def registrants():
    return render_template("registrants.html", registrants=REGISTRANTS)