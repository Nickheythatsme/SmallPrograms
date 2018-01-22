import sys
import os


def get_text(file_in):
    text = ''
    ignored = False
    if not os.path.exists(file_in): return 0;
    fin = open(file_in,'r')
    for line in fin:
        if '//\n' == line:
            ignored = not ignored
        if not ignored:
            text += line
    return text



def main():
    for i in range(1,len(sys.argv)):
        text = get_text(sys.argv[i])
        if text:
            text_len = len(text)
            text_words = len(text.split(' ')) + len(text.split('\n'))
            print("\
            File:     {}\n\
            Text len: {}\n\
            Words:    {}".format(sys.argv[i],text_len, text_words))

main()

