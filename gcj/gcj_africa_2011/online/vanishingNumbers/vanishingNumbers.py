import sys

intervals = [(0.0, 1.0)]
vanishings = []
vanish_order = {}
max_order_num = 0

for i in xrange(20):
    tmp_intervals = []
    tmp_vanishings = []
    for j in intervals:
        first = (j[1] - j[0]) * 1.0 / 3.0 + j[0]
        second = (j[1] - j[0]) * 2.0 / 3.0 + j[0]
        tmp_intervals.append((j[0], first))
        vanishings.append((first, second))
        tmp_intervals.append((second, j[1]))
        vanish_order[(first, second)] = i
    intervals = tmp_intervals
    max_order_num = i

vanishings.sort(key=lambda x: x[0])
vanishings.append((1.1, 1.2)) # sentinel
no_eliminated_index = max_order_num + 1

for test_num in xrange(int(raw_input())):
    N = int(raw_input())
    points = []

    for i in xrange(N):
        points.append(float(raw_input()))

    points.sort()

    points_order = {}
    for i in range(0, no_eliminated_index):
        points_order[i] = []
    points_order[no_eliminated_index] = []

    i = 0
    for v in vanishings:
        while i < len(points) and points[i] <= v[1]:
            if v[0] <= points[i] and points[i] <= v:
                points_order[vanish_order[v]].append(points[i])
            elif points[i] < v[0]:
                points_order[no_eliminated_index].append(points[i])
            i += 1
        if i >= len(points):
            break

#    print points_order

    print "Case #" + str(test_num + 1) + ":"
    for i in xrange(0, no_eliminated_index+1):
        points_order[i].sort()
        for j in points_order[i]:
            print j
