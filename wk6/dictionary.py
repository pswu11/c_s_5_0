words = set()
# dict() this will give you a hash table.
# set() this will give you a hash table without duplicates
def check(word):
    if word.lower() in words:
        return True
    else:
        return False

def load(dictionary):
    ...


def size():
    ...


def unload():
    ...

