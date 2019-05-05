# import time
# t = time.time()

# precalculations
# i, accumulator = 1, 0
# while accumulator < 1000000: 
# 	accumulator += len(str(i))
# 	i += 1 
# print i

string = ''
for i in xrange(1, 185187): 
	string += str(i)

product = 1
for i in xrange(0, 7): 
	product *= int(string[int(10 ** i - 1)])

print product

