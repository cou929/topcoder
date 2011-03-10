import sys

test_num = int(raw_input())

for test_case in range(1, test_num + 1):
    weights = map(int, raw_input().split())
    values = map(int, raw_input().split())
    weight_limit = int(raw_input())
    dp = [[0 for _ in xrange(weight_limit + 1)] for _ in xrange(2)]
    for i in range(1, len(weights)+1):
        for j in range(0, weight_limit + 1):
            tmp = dp[i%2][j-weights[i-1]] + values[i-1] if (weights[i-1] <= j) else dp[1-i%2][j]
            dp[i%2][j] = max(dp[1-i%2][j], tmp)
    print "Case #" + str(test_case) + ": " + str(dp[i%2][weight_limit])

