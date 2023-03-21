# implement credit card number validator

from cs50 import get_int


def main():
    while True:
        n = get_int("Number: ")
        """validate user input"""
        if isinstance(n, int):
            validate(n)
            break

def validate(number):
    n_list = []
    for char in str(number):
        n_list.append(int(char))
    if luhn_algo(n_list):
        print("T")
    else:
        print("Invalid credit card number.")


def luhn_algo(li):
    for i in range(len(li)):



main()