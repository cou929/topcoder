import math

def is_prime(x):
    if x == 2:
        return True

    n = int(math.ceil(math.sqrt(x)))
    for i in range(2, n + 1):
        if x % i == 0:
            return False
    return True

N = int(raw_input())
n = int(math.ceil(math.sqrt(N)))
ret = 0

for i in reversed(range(2, n + 1)):
    if N % i == 0 and is_prime(i):
        ret = i
        break

print ret
