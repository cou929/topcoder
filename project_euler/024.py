def fact(n):
    return reduce(lambda x, y: x * y, [i for i in range(1, n + 1)])

facts = [fact(i) for i in range(1, 10 + 1)]

def find(n, vec):
    if n == 0:
        vec.sort()
        vec.reverse()
        return reduce(lambda x, y: str(x) + str(y), vec)

    f = facts[len(vec) - 2]
    index = int(n / f)
    if n % f == 0:
        tmp = vec.pop(index - 1)
    else:
        tmp = vec.pop(index)

    return str(tmp) + str(find(n - f * index, vec))

print find(1000000, [0, 1, 2, 3, 4, 5, 6, 7, 8, 9])
