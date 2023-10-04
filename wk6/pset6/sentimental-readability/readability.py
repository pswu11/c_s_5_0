import cs50
import re


def main():
    t = cs50.get_string("Text: ").strip()
    letter_count = count_letters(t)
    word_count = count_words(t)
    sentence_count = count_sentences(t)
    print(t, letter_count, word_count, sentence_count)

    # calculate index
    L = letter_count / word_count * 100
    S = sentence_count / word_count * 100
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        print("Before Grade 1\n")
    elif index >= 16:
        print("Grade 16+")
    else:
        print("Grade: {0}".format(index))


def count_letters(text):
    count = 0
    for char in text:
        if str.isalpha(char):
            count += 1
    print(count)
    return count


def count_words(text):
    arr = text.split(" ")
    return len(arr)


def count_sentences(text):
    arr = re.split("[?!.]", text)
    return len(arr) - 1


main()
