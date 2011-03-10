# -*- coding: utf-8 -*-

import sys

problem_num = int(raw_input())

for problem_number in xrange(problem_num):
    s_len = int(raw_input())
    t_len = int(raw_input())
    s = raw_input()
    t = raw_input()

    dp = [[0 for _ in xrange(s_len + 1)] for _ in xrange(t_len + 1)]

    for i in range(1, s_len+1):
        for j in range(1, t_len+1):
            dp[i][j] = max(dp[i-1][j], dp[i][j-1])
            if s[i-1] == t[j-1]:
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1)
    
    for i in dp:
        print i

    sys.stdout.write('#' +  str(problem_num) + ': ' + str(dp[s_len][t_len]) + "\n")
