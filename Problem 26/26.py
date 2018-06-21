from decimal import *

def determineRecursionLength(n): 
	d = Decimal('1')
	getcontext().prec=10000
	postDecimal = str(d/n)
	postDecimal = postDecimal.replace("0.","")

	for i in xrange(0, len(postDecimal) / 2 + 1):
		for j in xrange(2, len(postDecimal) / 2 + 1):
			if postDecimal[i:i + j] == postDecimal[i + j:i + 2*j]:
		 		return j
	else: 
		return 0

	return postDecimal

maximumLength = 0
index = 0
for i in xrange(1, 999): 
	if determineRecursionLength(i) > maximumLength: 
		maximumLength = determineRecursionLength(i)
		index = i

print index, maximumLength