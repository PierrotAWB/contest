def isPrime(n): 
	if n < 2: 
		return False
	if n <= 3: 
		return True 
	for i in xrange(2, int(n**0.5) + 1): 
		if n % i == 0: 
			return False
	return True

def findPrimeDivisors(n): 
	divisors = []
	for i in xrange(1, int(n**0.5) + 1): 
		if n % i == 0: 
			divisors.append(i)
			if float(i) != n ** 0.5:
				divisors.append(n / i)
	primeDivisors = filter(lambda x: isPrime(x), divisors)
	return primeDivisors

# def createPrimeList(n): 
# 	primeList = []
# 	for i in xrange(2, n + 1): 
# 		if isPrime(i): 
# 			primeList.append(i)
# 	return primeList

# def findPrimeDivisors(n): 
# 	primeDivisor = []
# 	if isPrime(n): 
# 		primeDivisor.append(n)
# 		return primeDivisor

# 	primeList = createPrimeList(n / 2 + 1)

# 	for i in xrange(len(primeList)): 
# 		if n % primeList[i] == 0:  # divisor located
# 			primeDivisor.append(primeList[i])
# 			k = n 
# 			while k % primeList[i] == 0: 
# 				k /= float(primeList[i])
# 			n = int(k)

# 	return primeDivisor

def totient(n): 
	product = n
	primeDivisor = findPrimeDivisors(n)
	for i in xrange(len(primeDivisor)): 
		product *= (1 - (1 / float(primeDivisor[i])))
	return int(product)

maximumValue = 0
maxIndex = 0

for i in xrange(1, 1000001): 
	if i / float(totient(i)) > maximumValue: 
		maximumValue = i / float(totient(i))
		maxIndex = i

print maximumValue, maxIndex