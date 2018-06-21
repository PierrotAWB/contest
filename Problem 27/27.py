def isPrime(n):
	if n < 2: 
		return False
	if n <= 3: 
		return True
		
	for i in xrange(2, int(n ** 0.5) + 1):
		if n % i == 0: 
			return False
			break
	else: 
		return True

def createPrimeListUpTo(N):
	primeList = []
	for i in xrange(2, N): 
		if isPrime(i) == True: 
			primeList.append(i)

	return primeList

B_values = createPrimeListUpTo(1000)

def findLongestPrimeChain(a, b): 
	i = 0 

	while isPrime(i ** 2 + a * i + b) == True: 
		i += 1
	return i

maxValue = 0

for i in xrange(-999, 999, 2): 
	for j in B_values:
		if findLongestPrimeChain(i, j) > maxValue: 
			maxValue = findLongestPrimeChain(i, j)
			product = i * j

print product

