import cs50

def main():
    t = cs50.get_string("Text: ").strip()
    letter_count = count_letters(t)
    word_count = count_words(t)
    sentence_count = count_sentences(t)
    print(t, letter_count, word_count, sentence_count)

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
    arr = text.split('[?!.]')
    return len(arr) - 1

main()