import time 
t = time.time()

def sumOfDivisors(n): 
	accumulator = 1
	for i in xrange(2, int(n ** 0.5) + 1):
		if n % i == 0: 
			accumulator += i
			if i != n / i: 
				accumulator += n / i 
	return accumulator

def isAbundant(n):
	if n < 12: 
		return False
	elif sumOfDivisors(n) > n: 
		return True
	else: 
		return False

abundantList = []

for i in xrange(2, 28123):
	if isAbundant(i) == True: 
		abundantList.append(i)

markerList = [False] * 28123

for i in xrange(0, len(abundantList)):
	for j in xrange(i, len(abundantList)):
		if abundantList[i] + abundantList[j] <= 28123:
			markerList[abundantList[i] + abundantList[j] - 1] = True

accumulator = 0 
for i in xrange(0, 28123): 
	if markerList[i] == False: 
		accumulator += i + 1

print accumulator 

print "Run time: " + str(time.time() - t) + " seconds"
