T = int(raw_input())

for test_num in range(1, T + 1):
    ret = 0
    line = raw_input().split()
    N = int(line[0])
    seq = []

    for i in range(1, len(line), 2):
        seq.append((line[i], int(line[i+1])))

    cur_pos = {'O': 1, 'B': 1}
    others_duration = 0
    others_color = seq[0][0]

    for i in seq:
        color = i[0]
        dst = i[1]
        time = abs(cur_pos[color] - dst) + 1

        if others_color == color:
            ret += time
            others_duration += time
        else:
            if time > others_duration:
                diff = time - others_duration
                ret += diff
                others_duration = diff
            else:
                ret += 1
                others_duration = 1

        others_color = color
        cur_pos[color] = dst

    print "Case #{0}: {1}".format(test_num, ret)
    
