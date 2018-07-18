import sys

def divisors(n):
    valid_divs = []
    for i in range(1, int(n/2)+1):
        if float(n/i) == int(n/i):
            valid_divs.append(i)
    valid_divs.append(n)
    return valid_divs

def is_perfect(n):
    divs = divisors(n)
    return sum(divs) == int(2*n)

def amicable(a, b):
    return sum(divisors(a)) - a == b and sum(divisors(b)) - b == a


def main():
    if len(sys.argv) < 2:
        sys.exit()
    for arg in sys.argv[1:]:
        n = int(arg)
        print("divisors: {}\t Sum: {}".format(divisors(n), sum(divisors(n))))
        print("is perfect: {}".format(is_perfect(n)))

    print("amicable(

main()
