heros = {'Anka': 0, 'Chapay': 1, 'Cleo': 2, 'Troll': 3, 'Dracul': 4, 'Snowy': 5, 'Hexadecimal': 6}
graph = [[0 for i in xrange(len(heros))] for j in xrange(len(heros))]

likes = int(raw_input())

for i in xrange(likes):
    line = raw_input().split()
    print line[0] + " " + line[2]
    graph[heros[line[0]]][heros[line[2]]] = 1

exps = map(int, raw_input().split())
difs = 1000000000
team_nums = ()

for i in range(1, 5 + 1):
    for j in range(1, 6 - i + 1):
        k = 7 - i - j
        print i, j, k
        maxi = max(int(exps[0] / i), max(int(exps[1] / j), int(exps[2] / k)))
        mini = min(int(exps[0] / i), min(int(exps[1] / j), int(exps[2] / k)))
        if difs > maxi - mini:
            difs = maxi - mini
            team_nums = (i, j, k)



