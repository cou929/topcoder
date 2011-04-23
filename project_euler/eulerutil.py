#!/usr/bin/env python
# -*- coding:utf-8 -*-

from math import ceil, sqrt

def is_prime(x):
    if x <= 0:
        raise Exception("Prime number must be natural number grater than or equal to 2")
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    for i in range(3, int(ceil(sqrt(x))) + 1, 2):
        if x % i == 0:
            return False
    return True

def sieve(n):
    if n <= 0:
        return []

    search_set = [True for x in xrange(n+1)]
    prime_set = []

    search_set[0] = search_set[1] = False

    while search_set.count(True) > 0:
        cur = search_set.index(True)
        prime_set.append(cur)

        if cur * cur > n:
            for i in xrange(n+1):
                if search_set[i]:
                    prime_set.append(i)
            break

        num = cur
        while num <= n:
            search_set[num] = False
            num += cur

    return prime_set

def get_proper_divs(n):
    if n <= 0:
        raise Exception("Argument must be grater than 0")

    N = int(ceil(sqrt(n)))
    N += 1 if (N * N == n) else 0

    divs = [1]
    for i in range(2, N):
        if n % i == 0:
            divs.append(i)
            if n / i != i:
                divs.append(n / i)
    divs.sort()
    return divs
