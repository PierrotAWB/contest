import time
t = time.time()

def isOddComposite(n):
	if n % 2 == 0: 
		return False
	for i in xrange(2, int(n ** 0.5) + 1): 
		if n % i == 0: 
			return True
	return False

oddComposite = []
for i in xrange(1, 1000000): 
	if isOddComposite(i):
		oddComposite.append(i)

def isPrime(n): 
	if n == 2 or n == 3: 
		return True
	if n < 2:
		return False
	return not isOddComposite(n)

	# the first approach (subtracting primes and testing if twice a square is yielded)
	# proved inefficient. It was much faster to subtract perfect squares until a prime 
	# was yielded by testing the primality of the differences.

# a number is P2S if it can be written as the sum of a prime and twice a square
# def isP2S(n): 
# 	i = 0
# 	while prime[i] < n: 
# 		if ((n - prime[i]) / 2) ** 0.5 % 1 == 0: 
# 			return True
# 		else: 
# 			i += 1

# 	return False
def isP2S(n): 
	i = 1
	while n - 2 * i ** 2 >= 2: 
	 	if isPrime(n - 2 * i ** 2):
	 		return True
	 	else:  
			i += 1
	
	return False 

i = 0 
while isP2S(oddComposite[i]): 
	i += 1

print oddComposite[i]
print "Finished in " + str(time.time() - t) + " seconds."
