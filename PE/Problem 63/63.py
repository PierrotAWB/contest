def findPowerfulDigitCounts(a, b): #lower and upper bounds
	accumulator = 0
	for i in xrange(a, b): 
		print i
		j = 1
		counter = 0
		while len(str(j ** i)) <= i:
			if len(str(j ** i)) == i: 
				counter += 1
			j += 1
		accumulator += counter
	return accumulator

print findPowerfulDigitCounts(1, 100)