T = int(raw_input())
seq = []
ret = -1


def calc(pat1, pat2, sum, n):
    global seq
    global ret

    if n >= len(seq):
        if pat1 == pat2:
            ret = max(ret, max(sum, reduce(lambda x, y: x + y, seq) - sum))
        return

    calc(pat1 ^ seq[n], pat2, sum + seq[n], n + 1)
    calc(pat1, pat2 ^ seq[n], sum, n + 1)

for test_num in range(1, T + 1):
    ret = -1
    N = int(raw_input())
    seq = map(int, raw_input().split())
    total = reduce(lambda x, y: x + y, seq)

    for i in range(1, 2 ** N - 1):
        pat1 = 0
        pat2 = 0
        sum = 0

        for j in xrange(N):
            if i >> j & 1:
                pat1 ^= seq[j]
                sum += seq[j]
            else:
                pat2 ^= seq[j]

        if pat1 == pat2:
            ret = max(ret, max(sum, total - sum))

    ret = ret if ret != -1 else 'NO'
    print "Case #{0}: {1}".format(test_num, ret)
