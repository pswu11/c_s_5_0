from cs50 import get_string

# Program structure:
# you don't need prototype function.
# It's conventional to create a main function for your precedures.

def main():
    for i in range(3):
        meow()
        i += i


def meow():
    print("meow")

# Python style guide,
# double lines between the functions
# declare a main function at the beginning
# execute the main fuction at the bottom
main()

# Hello world

print("Hello, world!")

answer = get_string("What's your name? ")
print(f"Hello, {answer}!") # format string in Python

# data types: bool, float, int, str,
# no double or long as int and float already use larger range for them by default.
# Python doesn't have array, but list using []

# conditionals in Python

x = get_string("X: ")
y = get_string("Y: ")

if x > y:
    print("x is greater than y")
elif x < y:
    print("x is less than y")
else:
    print("x is equal to y")

# variables, no need to specify the data type
# since Python is dynamically typed

counter = 0
counter = counter + 1
counter += 1
# counter++ doesn't exist in Python

# loops in Python

i = 0
while i < 3:
    print("meow")
    i += i

for i in range(50):
    print(i)

# conditionals using list

s = input("Do you agree? [Y/N]")
# this returns a copy of s in lower case
# string is immutable in Python
s = s.lower()

if s in ["Y", "y"]:
    print("Agreed.")
elif s in ["N", "n"]:
    print("Not agreed.")

# functions with argument(s)

def whack(n):
    for i in range(n):
        print("whack!")

# in Python, it's "looser" with scopes when looping
# what is declared in the loop also exists outside of the loop
# when in the same function.


# Pythonic way to validate user input

def get_height():
    try:
        # try to get user input, and will keep trying
        n = int(input("Height: "))
        if n > 0:
            return n
    except ValueError:
        print("Input has to be a positive integer")

# you can also use try: with else:
# but it's not commonly used

# named arguement
print("?", end="")
print("?" * 4, end="")

# two-dimensional loop
# the default of print() always has \n at the end
# so no need to add it ourselves
for i in range(3):
    for j in range(4):
        print("#", end="")
    print()