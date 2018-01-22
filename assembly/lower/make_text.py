import random
import sys

def make_text(length):
    s = ''
    for i in range(length):
        s += chr(random.randint(32,126))
    return s

def main():
    if len(sys.argv) != 2:
        print("Usage: ./[exec] [number of characters]")
        sys.exit()
    s = make_text(int(sys.argv[1]))
    fout = open('text.txt','w')
    fout.write(s)
    fout.close()

main()


