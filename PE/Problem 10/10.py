# The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
# Find the sum of all the primes below two million.

# 2016=12=29

import time
t = time.time()

def createPrimeList(n):

	accumulator = 0 

	for i in range(2, n + 1):
		for j in range(2, int(i ** .5) + 1):
			# if j divides i at any point, break
			if i % j == 0:
				break
		else:
			accumulator += i 

	return accumulator

print createPrimeList(2000000)

print(time.time() - t)

# 25.8320000172
