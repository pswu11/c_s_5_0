import cs50

def main():
    t = cs50.get_string("Text: ")
    letter_count = count_letters(t)
    word_count = count_words(t)
    # sentence_count = count_sentences(t)
    print(t, letter_count, word_count)

def count_letters(text):
    return len(text)

def count_words(text):
    count = 0
    for char in text:
        if 
    print(text)
    return 3

main()