# -*- coding: utf-8 -*-

import sys

problem_num = int(raw_input())
memo = [[0 for _ in xrange(10)] for _ in xrange(10)]
dp_table = [[0 for _ in xrange(6)] for _ in xrange(5)]

def dfs(item, weight):
    print item, weight
    if item >= item_len:
        return 0
    elif weight < weights[item]:
        return dfs(item + 1, weight)
    else:
        return max(dfs(item + 1, weight), dfs(item + 1, weight - weights[item]) + values[item])

def memoize(item, weight):
    if memo[item][weight]:
        return memo[item][weight]

    print item, weight
    ret = 0

    if item >= item_len:
        ret = 0
    elif weight < weights[item]:
        ret = dfs(item + 1, weight)
    else:
        ret = max(dfs(item + 1, weight), dfs(item + 1, weight - weights[item]) + values[item])

    memo[item][weight] = ret
    return ret

def dp():
    for i in range(1, item_len + 1):
        for j in range(1, total + 1):
            if j - weights[i-1] >= 0:
                dp_table[i][j] = max(dp_table[i - 1][j], dp_table[i - 1][j - weights[i-1]] + values[i - 1])
            else:
                dp_table[i][j] = dp_table[i - 1][j]
    
    return dp_table[item_len][total]

for i in range(0, problem_num):
    item_len = int(raw_input())
    weights = map(int, raw_input().split())
    values = map(int, raw_input().split())
    total = int(raw_input())
    print item_len
    print weights
    print values
    print total

    print dfs(0, total)
    print memoize(0, total)
    for i in memo:
        print i

    print dp()
    for i in dp_table:
        print i
