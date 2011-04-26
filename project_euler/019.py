month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
total = 1
ret = 0

for i in range(1900, 2001):
    for j in range(0, len(month)):
        total += month[j]
        if j == 2 and i % 4 == 0 and i % 400 != 0:
            total += 1
        if total % 7 == 0 and i != 1900:
            ret += 1

print ret
