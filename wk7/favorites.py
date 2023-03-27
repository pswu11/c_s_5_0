import csv
from cs50 import SQL

with open("favorites.csv") as file:
    reader = csv.DictReader(file)
    counts = {}
    for row in reader:
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

favorite = input("Favorite: ")
if favorite in counts:
    print(f"{favorite:} {counts[favorite]}")


# open the existing database
db = SQL("sqlite:///favorites.db")

favorite = input("Favorite: ")

# SQL execute function here returns a dictionary of your SELECT query
rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = 'Mario';")
print(row[0]["n"])

