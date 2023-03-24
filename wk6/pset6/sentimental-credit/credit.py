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
    sum = 0
    for i in range(len(li)):
        index = -1-i
        if i % 2 == 0:
            print(li[index])
            sum += li[index]
            print(sum)
        else:
            print(li[index])
            double = li[index] * 2
            print(double)
            if double > 10:
                sum += (double / 10).floor + double % 10
            else:
                sum += double
            print(sum)

    print(sum)


main()