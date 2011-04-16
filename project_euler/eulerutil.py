#!/usr/bin/env python
# -*- coding:utf-8 -*-

import math

def is_prime(x):
    if x <= 0:
        raise Exception("Prime number must be natural number grater than or equal to 2")
    if x == 2:
        return True
    if x % 2 == 0:
        return False
    for i in range(3, int(math.ceil(math.sqrt(x))) + 1, 2):
        if x % i == 0:
            return False
    return True
