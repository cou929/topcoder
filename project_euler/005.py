import math

ret = 0
n = int(raw_input())
nums = [x for x in range(2, n+1)]

def is_prime(x):
    if x == 2:
        return True
    n = int(math.ceil(math.sqrt(x)))
    for i in range(2, n+1):
        if x % i == 0:
            return False
    return True

def ok(x):
    for i in nums:
        if x % i != 0:
            return False
    return True

primes = filter(lambda x: is_prime(x), nums)
factor = reduce(lambda x,y: x*y, primes)
i = 1

while i > 0:
    if ok(i * factor):
        ret = i * factor
        break
    i += 1

print ret

# 1  - ignore
# 2  - 2 ^ 1
# 3  - 3 ^ 1
# 4  - 2 ^ 1 * 2
# 5  - 5 ^ 1
# 6  - 2 ^ 1 * 3
# 7  - 7 ^ 1
# 8  - 2 ^ 3
# 9  - 3 ^ 2
# 10 - 2 ^ 1 * 5
#
# 2 ^ 3 * 3 ^ 2 * 5 ^ 1 * 7 ^ 1
