import time
def countSolutions(p): 
	counter = 0
	for a in xrange(1, p/3):
		for b in xrange(a, (p - a) / 2 + 1): 
			if (a ** 2 + b ** 2) ** 0.5 == p - a - b: 
				counter += 1
	return counter

currentMaximum = 0
maxP = 0
for i in xrange(0, 1001): 
	if countSolutions(i) > currentMaximum: 
		currentMaximum = countSolutions(i)
		maxP = i 

print maxP
print countSolutions(maxP)
