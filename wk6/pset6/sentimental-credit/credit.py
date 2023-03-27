# implement credit card number validator

from cs50 import get_int
import math


def main():
    while True:
        n = get_int("Number: ")
        """validate user input"""
        if isinstance(n, int):
            validate(n)
            break


# validate input credit card number
def validate(number):
    n_list = []
    for char in str(number):
        n_list.append(int(char))
    if luhn_algo(n_list):
        which_credit(n_list)
    else:
        print("INVALID")


# validate input using luhn algorithm
def luhn_algo(l):
    sum1 = 0
    sum2 = 0
    for i in range(len(l)):
        index = -1-i
        if i % 2 == 0:
            sum1 += l[index]
        else:
            double = l[index] * 2
            if double >= 10:
                sum2 += math.floor(double / 10) + double % 10
            else:
                sum2 += double
    if (sum1 + sum2) % 10 == 0:
        return True
    return False


# validate credit card provider
def which_credit(credit_list):
    length = len(credit_list)
    first_one = credit_list[0]
    first_two = credit_list[0] * 10 + credit_list[1]
    if length == 15:
        if first_two in [34, 37]:
            print("AMEX")
        else:
            print("INVALID")
    elif length == 16:
        if first_two in [51, 52, 53, 54, 55]:
            print("MASTERCARD")
        elif first_one == 4:
            print("VISA")
        else:
            print("INVALID")
    elif length == 14:
        if first_one == 4:
            print("VISA")
        else:
            print("INVALID")
    elif length == 13 and first_one == 4:
        print("VISA")
    else:
        print("INVALID")


main()