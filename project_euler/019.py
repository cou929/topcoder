month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
month_seq = [0]
ret = 0

for i in range(1900, 2001):
    for j in month:
        if j == 28:
            if i % 4 == 0 and not i % 400 == 0:
                month_seq.append(month_seq[-1] + j + 1);
        else:
            month_seq.append(month_seq[-1] + j);

for i in month_seq:
    if i % 7 == 0:
        ret += 1

print ret - 2
