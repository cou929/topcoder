from math import sqrt, ceil

N = 10000

def d(n):
    N = int(ceil(sqrt(n)))
    divs = [1]
    for i in range(2, N + 1):
        if n % i == 0:
            divs.append(i)
            if n / i != i:
                divs.append(n / i)
    return reduce(lambda x, y: x + y, divs)

amicable = []
for i in range(1, N + 1):
    res = d(i)
    if i == d(res) and i != res:
        if amicable.count(i) <= 0:
            amicable.append(i)
            amicable.append(res)

print amicable
print reduce(lambda x, y: x + y, amicable)
