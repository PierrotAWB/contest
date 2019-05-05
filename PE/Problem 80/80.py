'''
an implementation of a square root method 
using Newton's method. We solve x^2 - n = 0 
with initial guess x = int(sqrt(n)). 
It is known that Newton's method converges
very quickly, and hence, 20 iterations suffices.
'''

from decimal import *
import time
timeinit = time.time()
getcontext().prec = 102
sq = [1, 4, 9, 16, 25, 36, 49, 64, 81]
def newtonRoot(n): 
	xb = int(n ** 0.5)
	for i in range(20):
		xa = xb - (Decimal(xb) * Decimal(xb) - n) / (2 * Decimal(xb))
		xb = xa
	return xa
totalCount = 0
for i in range(1, 100):
	if i not in sq:
		s = str(newtonRoot(i))
		# remove decimal point
		t = s[0] + s[2:]
		# accumulate digit sum
		for j in range(100): 
			totalCount += int(t[j])
print totalCount
print "Execution time: " + str(time.time() - timeinit)
