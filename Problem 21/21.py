import time
t = time.time()

def isPrime(n): 
	if n == 2 or n == 3: 
		return True 
	for i in xrange(2, int(n ** 0.5) + 1):
		if n % i == 0: 
			return False
		else: 
			return True

def createPrimeList(n):

	primeList = []

	for i in xrange(2, int(n / 2) + 1):
		for j in xrange(2, int(i ** 0.5) + 1):
			if i % j == 0:
				break 
		else: 
			primeList.append(i)

	return primeList

def determinePrimePowers(n):

	powerList = []
	primeList = createPrimeList(n)

	for i in xrange(0, len(primeList)):
		counter = 0 
		k = n 

		while k / float(primeList[i]) % 1 == 0:
			k = k / primeList[i]
			counter += 1

		powerList.append(counter)

	return primeList, powerList

def d(n): 

	if n == 0: 
		return 0
	elif isPrime(n) == True:
		return 1

	product = 1
	primeList, powerList = determinePrimePowers(n)

	for i in xrange(0, len(powerList)):
		if powerList[i] != 0: 
			counter = 0

			for j in xrange(0, powerList[i] + 1):
				counter += primeList[i] ** j
			product *= counter

	return product - n
	
def isAmicable(n): 
	if n == d(d(n)) and n != d(n) and isPrime(n) == False: 
		return True
	else: 
		return False

counter = 0

for i in xrange(1, 10000):
	if isAmicable(i) == True: 
		counter += i

print counter

print "Finished in: " + str(time.time() - t) + " seconds"


