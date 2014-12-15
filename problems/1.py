#!/usr/bin/python

# Problem statement can be found here: http://code.google.com/codejam/contest/351101/dashboard#s=p0
import sys

def getinput(filename):
    content = []
    with open(filename) as f:
        content = f.readlines()
    return content

def determine(credit, items, prices):
    for i in range(0, len(prices)-1):
        for j in range(i+1, len(prices)):
            if prices[i] + prices[j] == credit:
                return prices[i], prices[j]
    

def main(argv):
    filename = sys.argv[1]
    content = getinput(filename)
    # We're going to assume that we don't need to error check the input
    for i in range(0, len(content)/3):
        # Separate input into variables
        credit = int(content[3*i])
        items = int(content[3*i+1])
        # Make prices into list based on spaces
        prices = content[3*i+2].split(' ')
        # Make each item in price an int
        prices = map(int, prices)
        item1, item2 = determine(credit, items, prices)
        print "Case %d: %d %d" % (i, item1, item2)
    
if __name__ == "__main__":
    main(sys.argv[1:])
