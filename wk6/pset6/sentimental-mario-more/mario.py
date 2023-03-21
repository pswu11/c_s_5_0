# Mario: implement double half-pyramid

from cs50 import get_int

def main():
    height = get_int("Height: ")
    print_pyramid(height)


def print_pyramid(height):
    for i in range(height):
        for j in range(height):
            print("#", end="")
        print()


main()