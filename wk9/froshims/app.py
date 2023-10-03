from flask import Flask, render_template, request

app = Flask(__name__)

# empty dictionary
registrants = {}

@app.route("/")
def index():
    return render_template("index.html")

@app.route("/register", methods=["POST"])
def register():
    name = request.form.get("name")
    sport = request.form.get("sport")
    registrants[name] = sport
    return render_template("success.html", name=name, sport=sport)

@app.route("/registrants")
def registrants():
    return render_template("registrants.html", registrants=registrants)