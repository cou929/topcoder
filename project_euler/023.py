from eulerutil import get_proper_divs

upper = 28123
abundants = []

for i in range(1, upper + 1):
    sum = reduce(lambda x, y: x + y, get_proper_divs(i))
    if sum > i:
        abundants.append(i)

memo = set()
for i in xrange(len(abundants)):
    for j in range(i, len(abundants)):
        memo.add(abundants[i] + abundants[j])

not_abundants = []
for i in range(1, upper + 1):
    if i not in memo:
        not_abundants.append(i)

print not_abundants
print reduce(lambda x, y: x + y, not_abundants)
        
