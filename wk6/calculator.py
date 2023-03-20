from cs50 import get_int

# the function has to be on top of where you call the function
def add(a, b):
    return a + b

x = get_int("x: ")
y = get_int("y: ")
print(x + y)

# the input function is a built-in function but always return a string
a = int(input("a: "))
b = int(input("b: "))
print(add(a, b))
# In C, this will rounds down the nearest integer (truncate)
# In Python, you'll get float automatically,
# but you only print a certain digits after the point
z = a / b
print(z)
# this shows more digits but still doesn't solve
# the floating point imprecision
# int overflow tho, is not a problem in Python
print(f"{z:.50f}")