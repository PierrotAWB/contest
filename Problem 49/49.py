import time
t = time.time() 

def isPrime(n): 
	for i in xrange(2, int(n**0.5) + 1): 
		if n % i == 0: 
			return False
	return True

prime = []
for i in xrange(1001, 10000): 
	if isPrime(i): 
		prime.append(i)

for i in xrange(0, len(prime)): 
	# all common differences must be even
	for j in xrange(2, int(0.5 * (9999 - prime[i])) + 1, 2):
		if isPrime(prime[i]) and isPrime(prime[i] + j) and isPrime(prime[i] + 2 * j): 
			if set(str(prime[i])) == set(str(prime[i] + j)) and set(str(prime[i])) == set(str(prime[i] + 2 * j)): 
				print prime[i], prime[i] + j, prime[i] + 2*j 

