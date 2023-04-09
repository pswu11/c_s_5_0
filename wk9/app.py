from flask import Flask, render_template, request
# flask library has all these functions above

# __name__ is used to check ... ?? this turns this file into a flask application.
app = Flask(__name__)


# @ is a decorator in Python, the fuction below is what server execute whenever a user visits
@app.route("/")
def index():
    # return "hello, world"
    # Use /URL/?name=David to dynamically change the name shown on the page
    if "name" in request.args:
        name = request.args["name"]
    else:
        # request.args returns dictionary (Flask version)
        name = "world"
    return render_template("index.html")

