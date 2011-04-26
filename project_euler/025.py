def fib(n):
    if n < 3:
        return 1
    a = 1
    b = 1
    ret = 0
    for i in range(3, n + 1):
        ret = a + b
        a = b
        b = ret
        if (len(str(ret)) == 1000):
            print i
    return ret

fib(5000)

# term = 13
# digits = 3
# a = 233
# b = 144

# while digits < 1000:
#     term += 1
#     tmp = a + b
#     print tmp, fib(term)
#     if tmp > 1000:
#         digits += 1
#         b = int(a / 10)
#         a = int(tmp / 10)
#     else:
#         b = a
#         a = tmp

# print term
