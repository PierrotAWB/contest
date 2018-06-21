import time
t = time.time()

def generatePascal(n): # n is the number of rows desired
	L = [[] for i in xrange(n)]
	L[0] = [1, 1]

	for i in xrange(1, len(L)): 
		for j in xrange(0, i + 2): 
			if j != 0 and j != i + 1: 
					L[i].append(L[i - 1][j - 1] + L[i - 1][j])
			else: 
				L[i].append(1)

	return L 

# main
counter = 0
candidates = generatePascal(100)
# for i in xrange(len(candidates)): 
# 	for j in xrange(len(candidates[i])): 
# 		if candidates[i][j] > 1000000: 
# 			counter += 1

# by arguments of symmetry and the fact that to the half point of Pascal's
# triangle, numbers in a row form a strictly increasing sequence, break if 1000000 
# is exceeded, add the appropriate amount to counter, and continue onto the next row
for i in xrange(len(candidates)): 
	for j in xrange(len(candidates[i])): 
		if candidates[i][j] > 1000000:
			counter += i + 2 - 2*j
			break
print counter
print "Finished in: " + str(time.time() - t) + " seconds."

# ans: 4075

# 1 1 
# 1 2 1
# 1 3 3 1
# 1 4 6 4 1
# 1 5 10 10 5 1 
# 1 6 15 20 15 6 1