def check_comb(last, seq):
    for i in seq:
        if last == i[0]:
            return i[1]
    return False

def check_oppos(target, seq):
    for i in seq:
        if target.count(i) > 0:
            return True
    return False

T = int(raw_input())

for test_num in range(1, T + 1):
    line = raw_input().split()
    combs = {}
    oppos = {}
    spells = ""
    ret = []

    # parse
    idx = 0
    C = int(line[idx])

    i = 0
    while i < C:
        i += 1
        idx += 1
        seq = line[idx]
        if combs.has_key(seq[0]):
            combs[seq[0]].append((seq[1], seq[2]))
        else:
            combs[seq[0]] = [(seq[1], seq[2])]
        if combs.has_key(seq[1]):
            combs[seq[1]].append((seq[0], seq[2]))
        else:
            combs[seq[1]] = [(seq[0], seq[2])]

    idx += 1
    D = int(line[idx])

    i = 0
    while i < D:
        i += 1
        idx += 1
        seq = line[idx]
        if oppos.has_key(seq[0]):
            oppos[seq[0]].append(seq[1])
        else:
            oppos[seq[0]] = [seq[1]]
        if oppos.has_key(seq[1]):
            oppos[seq[1]].append(seq[0])
        else:
            oppos[seq[1]] = [seq[0]]

    idx += 1
    N = int(line[idx])
    spells = line[idx + 1]

    # proccess spells
    for s in spells:
        if len(ret) < 1:
            ret.append(s)
        else:
            cur = s
            # check combine
            last = ret[-1]
            if combs.has_key(cur):
                res = check_comb(last, combs[cur])
                if res:
                    cur = res
                    ret.pop()

            # check opposite
            if oppos.has_key(cur) and check_oppos(ret, oppos[cur]):
                ret = []
            else:
                ret.append(cur)

    print "Case #{0}: [{1}]".format(test_num, ", ".join(ret))



