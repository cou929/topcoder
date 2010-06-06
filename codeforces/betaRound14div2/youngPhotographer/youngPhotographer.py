#!/usr/bin/python
import sys

tmp = raw_input().strip().split(' ')
x = int(tmp[1])
left = 0
right = 1000
ret = 0

for line in sys.stdin:
    tmp = line.strip().split(' ')
    left = max(left, min(int(tmp[0]), int(tmp[1])))
    right = min(right, max(int(tmp[0]), int(tmp[1])))
    if left > right:
        ret = -1
        break

if ret == -1:
    print -1
elif left <= x and x <= right:
    print 0
else:
    print min(abs(x - left), abs(x - right))
    

