# import decimal

def isConcealedSquare(n): # determine whether the necessary digits of n are where they're supposed to be.
	# assume that n will be 19 digits long.
	for i in xrange(0, 18, 2): # check if 1, 2, 3, 4, 5, 6, 7, 8, 9 are in their rightful place.
		if int(str(n)[i]) != i / 2 + 1: 
			return False
	if int(str(n)[-1]) == 0: # check if 0 is in its rightful place
		return True
	else: 
		return False

for i in xrange(0, 10): 
	print i 

	bottomBound = 0 
	for j in xrange(1, 10): 
		bottomBound += j * 10 ** (18 - 2 * (j - 1))
	bottomBound += i * 10 ** 17

	m = int(bottomBound ** 0.5)

	upperLimit = bottomBound # this is the bottom bound with all of the rest of the "_" equal to 9.
	for j in xrange(1, 9): 
		upperLimit += 9 * 10 ** (2 * j - 1)

	found = False

	while not found: 
		if isConcealedSquare(m ** 2): 
			print m ** 2
			found = True
		if m ** 2 > upperLimit: 
			break 
		else: 
			m += 1


		


