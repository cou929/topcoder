T = int(raw_input())

for test_num in range(1, T + 1):
    N = int(raw_input())
    seq = map(int, raw_input().split())
    total = reduce(lambda x,y: x+y, seq)
    patrick_total = reduce(lambda x,y: x^y, seq)
    mini = min(seq)

    if patrick_total != 0:
        ret = 'NO'
    else:
        ret = total - mini

    print "Case #{0}: {1}".format(test_num, ret)
