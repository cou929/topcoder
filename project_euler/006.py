import math

n = 100

sum_of_square = reduce(lambda x,y: x+y, [x * x for x in range(1, n + 1)])
square_of_sum = pow(reduce(lambda x,y: x+y, [x for x in range(1, n + 1)]), 2)

print 'n: ', n
print 'sum of square: ', sum_of_square
print 'square of sum', square_of_sum
print 'difference: ', (square_of_sum - sum_of_square)
