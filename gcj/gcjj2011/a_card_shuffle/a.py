#! /usr/bin/python

T = int(raw_input())

for testcase in range(1, T + 1):
    (M, C, W) = map(int, raw_input().split())
    cuts = []
    ret = 0

    for i in xrange(C):
        (A, B) = map(int, raw_input().split())
        cuts.append((A, B))

    print M, C, W
    print cuts

    i = 1
    while i <= M:
        if i % 10000000 == 0:
            print i

        cur_pos = i

        for j in cuts:
            if (j[0] + j[1] - 1) < cur_pos:
                continue
            if j[0] <= cur_pos:
                cur_pos = cur_pos - j[0] + 1
            else:
                cur_pos += j[1]

        if cur_pos == W:
            ret = W
            break

        i += 1

    print 'Case #', str(testcase), ': ', str(ret)
