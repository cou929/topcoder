import math

def get_divisor_num(x):
    ret = 0

    for i in range(1, int(math.ceil(math.sqrt(x)))):
        if x % i == 0:
            ret += 2 if x / i != i else 1

    return ret

div_num = 500
tri_num = 0
large = 10000000

for i in xrange(large):
    tri_num += i
    if get_divisor_num(tri_num) > div_num:
        break

print tri_num
