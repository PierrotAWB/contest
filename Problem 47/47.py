import time
t = time.time()

def isPrime(n): 
	if n < 2: 
		return False
	if n <= 3: 
		return True
	for i in xrange(2, int(n ** 0.5) + 1): 
		if n % i == 0: 
			return False
	return True

# generate prime list
prime = [] 
for i in xrange(2, 500000): 
	if isPrime(i): 
		prime.append(i)

def hasFourDistinctPrimeFactors(n): 
	i = 0
	factors = []
	while n / float(prime[i]) >= 1:
		if prime[i] not in factors and (n / float(prime[i])) % 1 == 0:
			factors.append(prime[i])
			k = n 
			while k / float(prime[i]) % 1 == 0: 
				k /= float(prime[i])
			n = k
		i += 1
	if len(factors) == 4: 
		return True
	return False

# for i in xrange(1, 500000): 
# 	print i
# 	for j in xrange(0, 4): 
# 		if hasFourDistinctPrimeFactors(i + j) == False:
# 			break 
# 	else: 
# 		print "*****************" + str(i) + "*******************"
# 		break

found = False
i = 1
while not found:
	print i
	if hasFourDistinctPrimeFactors(i):
		if hasFourDistinctPrimeFactors(i + 1): 
			if hasFourDistinctPrimeFactors(i + 2): 
				if  hasFourDistinctPrimeFactors(i + 3): 
					found == True
					break
				else: 
					i += 4
			else: 
				i += 3
		else: 
			i += 2
	else: 
		i += 1

print "*****************" + str(i) + "*******************"
print "Finished in: " + str(time.time() - t) + " seconds." 
