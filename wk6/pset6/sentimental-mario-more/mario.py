# Mario: implement double half-pyramid

from cs50 import get_int


# main fuction
def main():
    while True:
        h = get_int("Height: ")
        """validate user input"""
        if h >= 1 and h <= 8:
            print_pyramid(h)
            break


# print double-pyramid based on height as argument
def print_pyramid(height):
    for i in range(height):
        i += 1
        """print the left pyramid"""
        print(" " * (height - i), end="")
        print("#" * i, end="")
        print(" " * 2, end="")
        """print the right pyramid"""
        print("#" * i, end="")
        print(" " * (height - i))


main()