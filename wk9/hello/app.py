from flask import Flask, render_template, request
# flask library has all these functions above

# __name__ is used to check if the name of the file was itself (current file)
# Basically, turns this turns this file into a flask application.
app = Flask(__name__)


# @ is a decorator in Python, the fuction below is
# what server execute whenever a user visits
# / here means home (index.html)

# @app.route("/")
# def index():
#     if "name" in request.args:
#         name = request.args["name"]
#     else:
#         name = "world"
#     # name (on the left) is the value of the name arg, this is required to display name variable
#     return render_template("index.html", name=name)

@app.route("/")
def index():
    return render_template("index.html", name=request.args.get("name", "world"))

"""
@app.route("/greet")
def greet():
    return render_template("greet.html", name=request.args.get("name", "world"))
"""

# This allows our Flask app to support POST method, instead of just GET.
# This helps you to hide the information instead of showing it on URL.
# POST is like a virtual envolope, but it doesn't make it safe.
# It's still visible in Network tab > Payload in the browser!!
# methods=["GET", "POST"] supports both method.
@app.route("/greet", methods=["POST"])
def greet():
    # get arg "name", if not existing then name = "world"
    return render_template("greet.html", name=request.args.get("name", "world"))