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
    luhn_algo(n_list)



def luhn_algo(li):
    sum1 = 0
    sum2 = 0
    for i in range(len(li)):
        if i % 2 == 0:
            print(li[-1-i])
            sum1 += li[-1-i]
            print(sum1)
        else:
            print(li[-1-i])
            sum2 += li[-1-i] * 2
    sum1_list = []
    for char in sum1:
        sum1_list.append(char)
    print(sum1_list)

main()