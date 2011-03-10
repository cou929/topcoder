import sys

testnum = int(raw_input())

for testcase in range(1, testnum+1):
    N = int(raw_input())
    R = int(raw_input())
    graph = [[0 for x in xrange(N)] for x in xrange(N)]
    city_label = [0 for x in xrange(N)]
    color = 0
    degree = []

    # make graph
    for i in range(0, R):
        road = map(int, raw_input().split())
        graph[road[0]][road[1]] += 1
        graph[road[1]][road[0]] += 1

    # find degrees for each city
    degree = [reduce(lambda x,y: x+y, graph[i]) for i in xrange(len(graph))]

    # find jointing groups
    for i in range(0, N):
        if degree[i] > 0 and city_label[i] == 0:
            color += 1
            stack = []
            stack.append(i)
            while len(stack) > 0:
                cur = stack.pop()
                city_label[cur] = color
                for j in xrange(len(graph[cur])):
                    if city_label[j] == 0 and graph[cur][j] > 0:
                        stack.append(j)

    # find odd degree for each group
    odd_nums_for_group = [0 for i in xrange(color)]
    for i in xrange(len(city_label)):
        if degree[i] % 2 == 1:
            odd_nums_for_group[city_label[i]-1] += 1

    # connect each groups
    # FIXME LATER
    if len(odd_nums_for_group) > 1:
        for i in xrange(len(odd_nums_for_group)-1):
            odd_nums_for_group[i] = odd_nums_for_group[i] - 1 if odd_nums_for_group[i] > 0 else odd_nums_for_group[i] + 1
            odd_nums_for_group[i+1] = odd_nums_for_group[i+1] - 1 if odd_nums_for_group[i+1] > 0 else odd_nums_for_group[i+1] + 1
        odd_nums_for_group[0] = odd_nums_for_group[0] - 1 if odd_nums_for_group[0] > 0 else odd_nums_for_group[0] + 1
        odd_nums_for_group[len(odd_nums_for_group)-1] = odd_nums_for_group[len(odd_nums_for_group)-1] - 1 if odd_nums_for_group[len(odd_nums_for_group)-1] > 0 else odd_nums_for_group[len(odd_nums_for_group)-1] + 1

    # count new road we need
    odd_num = reduce(lambda x,y: x+y, odd_nums_for_group)
    odd_num /= 2
    if color > 1:
        odd_num += color

    print "Case #" + str(testcase) + ": " + str(odd_num)
    
