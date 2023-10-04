import cs50

def main():
    t = cs50.get_string("Text: ")
    letter_count = count_letters(t)
    word_count = count_words(t)
    # sentence_count = count_sentences(t)
    print(t, letter_count, word_count)

def count_letters(text):
    count = 0
    for char in text:
        if str.isalpha(char):
            count += 1
    print(count)
    return count

def count_words(text):
    count = 0
    arr = text.trim().split(" ")
    for i in arr:
        print(i)
    return len(arr)

main()