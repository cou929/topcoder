import sys

def ok(D, radios):
    min_position = 0
    max_position = 0

    for i in radios:
        max_position = max(max_position, i[0])

    maxi = max_position
    min_position = radios[0][0] - D
    max_position = radios[0][0] + D
    for i in range(1, len(radios)):
        tmp_min = min_position - (radios[i][1] - radios[i-1][1])
        tmp_max = max_position + (radios[i][1] - radios[i-1][1])
        min_position = max(radios[i][0] - D, tmp_min)
        max_position = min(radios[i][0] + D, tmp_max)
        if min_position > max_position:
            return False

    return True

for test_num in xrange(int(raw_input())):
    N = int(raw_input())
    radios = []
    for i in xrange(N):
        radios.append(map(lambda x: int(x) * 2.0, raw_input().split()));
    radios.sort(key=lambda x: int(x[1]))

    max_position = 0
    for i in radios:
        max_position = max(max_position, i[0])

    left = 0
    right = max_position
    mid = right

    for i in xrange(100):
        mid = (left + right) / 2.0
        if (ok(mid, radios)):
            right = mid
        else:
            left = mid

    print "Case #" + str(test_num+1) + ": " + str(round(mid/2.0, 9))
