# The prime factors of 13195 are 5, 7, 13 and 29.
# What is the largest prime factor of the number 600851475143?
# 2016-12-29

# create a list of primes not exceeding n
primeList = []
greatestPrimeDivisor = 0

def createPrimeList(n):
	for i in range(1, n):
		# test if i is a prime
		for j in range(2, sqrt(i)):
			if i % j == 0:
				break
		else: 
			primeList.append(i)

createPrimeList(59568)
print primeList


# create a function to test if a number is divisible by the primes in the prime list

def determineGreatestPrimeDivisor(n): 
	for i in range(1, len(primeList)):
		if n % primeList[i] == 0: 
			greatestPrimeDivisor = primeList[i]
			n = n / primeList[i]
	return greatestPrimeDivisor

print determineGreatestPrimeDivisor(59569)


# note: this is not automated; it only serves a calculator of sorts