def findDiagonalSum(NumberOfRings):
	accumulator = 0
	
	for i in xrange(2, NumberOfRings + 1):
		accumulator += 4 * ((2 * i - 1) ** 2) - 12 * (i - 1)

	return accumulator + 1

print findDiagonalSum(501)
