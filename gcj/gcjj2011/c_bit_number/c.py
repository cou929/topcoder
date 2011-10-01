#! /usr/bin/python

import math


def get_bits(n):
    ret = 0
    while n > 1:
        if n % 2 == 1:
            ret += 1
        n /= 2
    return ret + 1


def check_bits(n):
    ret = True

    while n > 1:
        if n % 2 == 0:
            ret = False
            break
        n /= 2

    return ret


T = int(raw_input())

for testcase in range(1, T + 1):
    n = int(raw_input())
    ret = 0

    if check_bits(n):
        ret = get_bits(n)
    else:
        can = 1
        while n > can:
            can *= 2

        A = can / 2 - 1
        B = n - A

        ret = get_bits(A) + get_bits(B)

    print 'Case #' + str(testcase) + ': ' + str(ret)
