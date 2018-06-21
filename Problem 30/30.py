def isPDI(n): 
	digitSum = 0

	for i in xrange(0, len(str(n))): 
		digitSum += int(str(n)[i]) ** 5 

	if digitSum == n: 
		return True
	else: 
		return False

accumulator = 0

for i in xrange(2, 1000000): 
	if isPDI(i): 
		print i
		accumulator += i

print accumulator 