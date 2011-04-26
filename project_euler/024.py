def fact(n):
    return reduce(lambda x, y: x * y, [i for i in range(1, n + 1)])

facts = [fact(i) for i in range(1, 10 + 1)]

print facts
