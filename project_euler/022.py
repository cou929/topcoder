sum = 0
names = map(lambda x: x.replace('"', ''), raw_input().split(','))
names.sort()

for i in xrange(len(names)):
    sum += reduce(lambda x, y: x + y, [ord(x) - ord('A') + 1 for x in names[i]]) * (i + 1)

print sum
