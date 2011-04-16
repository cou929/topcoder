import math
from eulerutil import is_prime

nth = 10001
count = 0
num = 1

while count < nth:
    num += 1
    if is_prime(num):
        count += 1

print nth, 'th prime is', num
