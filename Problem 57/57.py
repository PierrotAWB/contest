def expansion(n): 
	denominator = 2
	numerator = 1
	for i in xrange(1, n): 
		numerator += 2 * denominator
		temp = numerator
		numerator = denominator
		denominator = temp
	numerator += denominator
	return numerator, denominator
counter = 0 
print expansion(1)
for i in xrange(1, 1001): 
	if len(str(expansion(i)[0])) > len(str(expansion(i)[1])):
		counter += 1

print counter
