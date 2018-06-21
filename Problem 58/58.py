import time
t = time.time()

def findDiagonalNumbers(sideLength): # creates an array of numbers on diagonals
	# assert that sideLength will be odd
	diagonalNumber = []
	for i in xrange(1, sideLength + 1, 2): 
		diagonalNumber.append(i ** 2)
		if i > 1: 
			for j in xrange(1, 4): 
				diagonalNumber.append(i ** 2 - (i - 1) * j)
	return diagonalNumber

# print len(findDiagonalNumbers(7))

def isPrime(n): # discern whether a number is prime
	if n < 2: 
		return False
	if n <= 3:
		return True
	for i in xrange(2, int(n**0.5) + 1): 
		if n % i == 0: 
			return False
	return True

memoTable = {1:0}
def countPrimes(sideLength): # recursively count the number of primes sitting on diagonals
	if sideLength not in memoTable:
		additional = 0
		for i in xrange(0, 4): 
			if isPrime(sideLength ** 2 - (sideLength - 1) * i):
				additional += 1
		memoTable[sideLength] = countPrimes(sideLength - 2) + additional
	return memoTable[sideLength]

i = 3
found = False
while not found: 
	if countPrimes(i) / float(len(findDiagonalNumbers(i))) < 0.1:
		found = True
	else: 
		i += 2 

print i	
print "Finished in: " + str(time.time() - t) + " seconds."


