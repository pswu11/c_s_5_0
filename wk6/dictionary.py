"""
This is basically a mockup how we'd solve problem set 5 from last week in Python.
"""

words = set()
"""
dict() this will give you a hash table.
set() this will give you a hash table without duplicates
"""
def check(word):
    if word.lower() in words:
        return True
    else:
        return False

def load(dictionary):
    file = open(dictionary, "r")
    for line in file:
        # this removes trailing charactors from the line
        word = line.rstrip()
        # this adds word to our set
        words.add(word)
    file.close()
    return True


def size():
    return len(words)


# no need to do memory management in Python
def unload():
    return True

