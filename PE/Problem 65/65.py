import time
t = time.time()

def generateConvergent(n): # nth permutation

	def calculateStep(n): 
		if n % 3 != 2: 
			return 1
		else: 
			return 2 * (n // 3 + 1)

	denominator = calculateStep(n)
	numerator = 1

	for i in xrange(1, n): 
		numerator += calculateStep(n - i) * denominator
		temp = numerator
		numerator = denominator
		denominator = temp
	numerator += 2 * denominator

	return numerator, denominator

accumulator = 0
for i in xrange(len(str(generateConvergent(99)[0]))): 
	accumulator += int(str(generateConvergent(99)[0])[i])

print accumulator
print "Finished in: " + str(time.time() - t) + " seconds."
		



