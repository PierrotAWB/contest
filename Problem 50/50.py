import time
t = time.time() 

def isPrime(n): 
	if n < 2: 
		return False
	if n <= 3:
		return True
	for i in xrange(2, int(n**0.5) + 1): 
		if n % i == 0: 
			return False
	return True

prime = []
for i in xrange(0, 1000000): 
	if isPrime(i): 
		prime.append(i)

# try with different chain lengths: 
currentMaximum = 0

def maxSummablePrime(limit):
	currentMaximum = 0 
	# chain lengths
	for i in xrange(1, 600): 
		# starting points
		for j in xrange(0, i): 
			accumulator = 0
			# add the n primes from the starting point where n = chain length
			for k in xrange(j, j + i): 
				accumulator += prime[k]
			
			if isPrime(accumulator) and i > currentMaximum and accumulator < limit: 
				currentMaximum = i
				targetPrime = accumulator

	return targetPrime
print maxSummablePrime(1000000)


#######brute force######
# maxChain = 0

# # targets
# for i in xrange(0, len(prime)): 
# 	print i
# 	# "heads" of the chain
# 	for j in xrange(i - maxChain + 1, -1, -1):
# 		if i < maxChain:
# 			break
# 		# initiate the incrementor (k), the counter (yield length of chain), and
# 		# accumulator (to break sum if target is exceeded)
# 		k = j
# 		counter = 0
# 		accumulator = 0

# 		# while the accumulator has not exceeded the target, add the next prime 
# 		# in the prime list (start with the head of the chain) and increment the counter
# 		while accumulator < prime[i]:
# 			accumulator += prime[k]
# 			counter += 1
# 			# check if the target has been hit, if yes, break
# 			if accumulator == prime[i]: 
# 				break
# 			# increment the index incrementor
# 			k += 1
# 		# if target is hit and the chain is longer than the current max, 
# 		# save the target and chain length
# 		if accumulator == prime[i] and counter > maxChain: 
# 			maxChain = counter
# 			targetPrime = prime[i]

# print targetPrime, maxChain
print "Finished in: " + str(time.time() - t) + " seconds."

	
