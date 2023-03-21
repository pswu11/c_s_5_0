from cs50 import get_string

# Program structure:
# you don't need prototype function.
# It's conventional to create a main function for your precedures.

def main():
    for i in range(3):
        meow()

def meow():
    print("meow")

main()

# Hello world

print("Hello, world!")

answer = get_string("What's your name? ")
print(f"Hello, {answer}!") # format string in Python

# data types: bool, float, int, str,
# no double or long as int and float already use larger range for them by default.
# Python doesn't have array, but list using []

# conditionals in Python

if x > y:
    print("x is greater than y")
elif x < y:
    print("x is less than y")
else:
    print("x is equal to y")

# variables, no need to specify the data type

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