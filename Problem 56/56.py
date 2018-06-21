import time 
t = time.time()
def calcDigitalSum(n): 
	accumulator = 0
	for i in xrange(len(str(n))): 
		accumulator += int(str(n)[i])
	return accumulator

maximumDigitalSum = 0

for a in range(100): 
	for b in range(100): 
		if calcDigitalSum(a ** b) > maximumDigitalSum: 
			maximumDigitalSum = calcDigitalSum(a ** b)

# print max(sum(map(int, a ** b for a, b in xrange(0, 100))))
# L = max([sum(map(int, (i for i in [str(a ** b) for a in range(100) for b in range(100)])))])
# L = max([[sum(map(int, (i for i in [str(a ** b) for a in range(100) for b in range(100)])))] for i in xrange(99 * 99)])
# print L
# for i in a ** b for a in range(5) for b in range(5):
# 	print i

print maximumDigitalSum
print "Finished in: " + str(time.time() - t) + " seconds."

# ans: 972

