import csv
from cs50 import SQL

with open("favorites.csv") as file:
    # reader = csv(file) only returns row as list, but doesn't consider the headers
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

# CS50's SQL execute function returns a dictionary of your SELECT query
# And this is how to utilize SQL results in the Python program
rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = 'Mario'")
print(row[0]["n"])

# The right way of plugging user input:
rows_better = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE problem = ?", favorite)

