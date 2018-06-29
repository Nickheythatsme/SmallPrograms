import sys

def test_congruence(a, b, m):
    print("{} % {} = {}".format(b, m, b % m))
    print("{} == {} % {}: {}".format(a, b, m, a == b % m))
    return a == b % m
    

def main():
    if len(sys.argv) != 4:
        print("Usage: python congruence [a] [b] [m]")
        print("output: a = b (mod m)")
        sys.exit(1)

    a = int(sys.argv[1]) 
    b = int(sys.argv[2]) 
    m = int(sys.argv[3])
    test_congruence(a, b, m)

main()
