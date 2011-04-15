import math

def is_palindrome(s):
    for i in xrange(int(len(s)/2)):
        if s[i] != s[-i - 1]:
            return False
    return True

ret = 0

for i in range(100, 1000):
    for j in range(i, 1000):
        if is_palindrome(str(i * j)):
            ret = max(ret, i * j)

print ret
