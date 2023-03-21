# Mario: implement double half-pyramid

from cs50 import get_int

def main():
    try:
        h = get_int("Height: ")
        if h >= 1 and h <= 8:
            print_pyramid(h)
        else: 



def print_pyramid(height):
    for i in range(height):
        i += 1
        print(" " * (height - i), end="")
        print("#" * i, end="")
        print(" ", end="")
        print("#" * i, end="")
        print(" " * (height - i))

main()