# Mario: implement double half-pyramid

from cs50 import get_int

def main():
    height = get_int("Height: ")
    print_pyramid(height)


def print_pyramid(height):
    for i in range(height):
        for j in range(height-1):
            j += 1
            print(" " * (height - j), end="")
            print("#" * j)
        i += 1


main()