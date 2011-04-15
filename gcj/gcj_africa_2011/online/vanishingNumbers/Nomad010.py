from decimal import *

def conv(num):
    res = ""
    num = Decimal(num)
    while len(res) < 100:
        #print num, res
        
        if num*Decimal("3.0") < Decimal("1.0"):
            res += "0"
            num = num*Decimal("3.0")
        elif num*Decimal("3.0") < Decimal("2.0"):
            return res
            #num = num*3.0 - 1.0
        else:
            res += "2"
            num = num*Decimal("3.0") - Decimal("2.0")
            #num = num*3.0 - 2.0
    
    return res
    

T = int(raw_input())

for t in range(1, T+1):
    print "Case #%d:" % t
    
    N = int(raw_input())
    
    numbers = []
    lens = []
    for i in range(N):
        numbers += [str(raw_input())]
        lens += [(len(conv(numbers[-1])), numbers[-1])]
    
    lens.sort()
    for x, y in lens:
        print y
    