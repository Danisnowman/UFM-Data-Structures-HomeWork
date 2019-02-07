import operator


# class Main:
#    def __init__(self, text, filename, txt_file):
#        self.count = 0
#        self.text = text
#        self.filename = filename
#        self.txt_file = txt_file

# def count_a_letter(text, letter):
#    count = 0
#   for c in text:
#        count += (c == letter)
#    return count

# fileToRead = open("test.txt")
# print("A: {0}".format(str(count_a_letter(fileToRead.read(), "a"))))

def count_letters(filename):
    letters = {}
    for n in filename:
        keys = letters.keys()
        if n in keys:
            letters[n] += 1
        else:
            letters[n] = 1
    return letters


def read_and_sort(txt_file):
    with open(txt_file, 'r') as file_to_read:
        file_to_read = file_to_read.read()
        # file_to_read = [line.replace(' ', '') for line in file_to_read]

    unsorted_dictionary = count_letters(file_to_read)
    for key, value in reversed(sorted(unsorted_dictionary.items(), key=operator.itemgetter(1))):
        print(str(key).upper() + ":", value, int(value) * '*')


read_and_sort('test.txt')
