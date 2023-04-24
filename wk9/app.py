from flask import Flask, render_template, request
# flask library has all these functions above

# __name__ is used to check if the name of the file was itself (??)
# Basically, turns this turns this file into a flask application.
app = Flask(__name__)


# @ is a decorator in Python, the fuction below is
# what server execute whenever a user visits
@app.route("/")
def index():
    name = request.args.get("name", "world")
    return render_template("index.html", name=name)