import math, time
t = time.time()

# using math.factorial
# def isCurious(n): 
# 	if n == 1 or n == 2: 
# 		return False
# 	accumulator = 0
# 	for i in xrange(0, len(str(n))): 
# 		accumulator += math.factorial(int(str(n)[i]))
# 	if accumulator == n: 
# 		return True
# 	else: 
# 		return False

# using a dictionary 
# def isCurious(n): 
# 	m = {0 : 1, 1 : 1, 2 : 2, 3 : 6, 4 : 24, 5 : 120, 6 : 720, 7 : 5040, 8 : 40320, 9 : 362880}
# 	if n == 1 or n == 2: 
# 		return False
# 	accumulator = 0
# 	for i in xrange(0, len(str(n))): 
# 		accumulator += m[int(str(n)[i])]
# 	if accumulator == n: 
# 		return True
# 	else: 
# 		return False

# using a list
def isCurious(n): 
	m = [1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
	if n == 1 or n == 2: 
		return False
	accumulator = 0
	for i in xrange(0, len(str(n))): 
		accumulator += m[int(str(n)[i])]
	if accumulator == n: 
		return True
	else: 
		return False

accumulator = 0
for i in xrange(1, 100000):
	if isCurious(i): 
		accumulator += i 

print accumulator 
print "Finished in: " + str(time.time() - t) + " seconds."