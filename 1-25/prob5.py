# 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
# 2016-12-29

primeList = []
power = []

# determine all prime numbers not exceeding n
def createPrimeList(n):
	for i in range(2, n + 1):
		for j in range(2, i):
			# check if j divides i at any time
			# if j|i, break 
			if i % j == 0: 
				break
		else:
			primeList.append(i)

	return primeList

def determineHighestPrimePowers(n):
	for i in range(0, len(primeList)):

		counter = 0
		k = n

		while k / primeList[i] >= 1:
			k = k / primeList[i]
			counter += 1

		power.append(counter)

	return power

print createPrimeList(20), determineHighestPrimePowers(20)

def determineSmallestMultiple(n):

	product = 1

	for i in range(0, len(primeList)):
		product = product * primeList[i] ** power[i]

   	return product 

print determineSmallestMultiple(20)
