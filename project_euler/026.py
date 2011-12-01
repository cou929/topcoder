maxi = 0
result = -1

for i in range(2, 1001):
    memo = []
    n = 1
    memo.append(n)
    while True:
        n = n * 10 % i
        if memo.count(n) > 0:
            if maxi < (len(memo) - memo.index(n)):
                maxi = len(memo) - memo.index(n)
                result = i
            break
        elif n == 0:
            break
        memo.append(n)
        
print result
