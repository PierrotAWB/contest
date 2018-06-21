import time
t = time.time()

def isPrime(n): 
	if n < 2: 
		return False
	elif n <= 3: 
		return True
	else: 
		for i in xrange(2, int(n ** 0.5) + 1): 
			if n % i == 0: 
				return False
				break
		else: 
			return True

def isTruncatable(n): 
	if n == 2 or n == 3 or n == 5 or n == 7: 
		return False
	if isPrime(n) == False: 
		return False

	# strip from left to right
	for i in xrange(0, len(str(n))): 
		if isPrime(int(str(n)[0:len(str(n)) - i])) == False: 
			return False
			break
	
	# strip from right to left
	for i in xrange(0, len(str(n))): 
		if isPrime(int(str(n)[i:len(str(n))])) == False: 
			return False
			break

	else: 
		return True

sol = []
for i in xrange(0, 1000000):
	if isTruncatable(i): 
		sol.append(i)

print sum(sol), len(sol)
print "Finished in: " + str(time.time() - t) + " seconds."