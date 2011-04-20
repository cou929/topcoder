# this is same to 018.py

N = int(raw_input())

tree = []
dp = [[0 for i in xrange(N)] for j in xrange(N)]

for i in xrange(N):
    tmp = map(int, raw_input().split())
    for i in xrange(N - len(tmp)):
        tmp.append(0)
    tree.insert(0, tmp)

for row in xrange(N):
    for col in xrange(N - row):
        if row > 0:
            dp[row][col] = tree[row][col] + max(dp[row-1][col], dp[row-1][col+1])
        elif row == 0:
            dp[row][col] = tree[row][col]

print dp[N-1][0]
