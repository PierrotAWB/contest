# What is the 10 001st prime number?

primeList = []
# find the nth prime number
def createPrimeList(n, k):
	for i in range(2, n + 1):
		for j in range(2, int(i ** .5) + 1):
			# check if i is prime
			# if not, break
			if i % j == 0:
				break
		else: 
			primeList.append(i)

	return primeList[k]

print createPrimeList(1000000, 10000)