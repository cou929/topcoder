n = 100
print reduce(lambda x, y: x + y, [int(s) for s in str(reduce(lambda x, y: x * y, [i for i in range(1, n + 1)]))])
