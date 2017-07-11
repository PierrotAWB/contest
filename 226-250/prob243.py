def isPrime(n): 
	if n < 2: 
		return False
	if n <= 3: 
		return True 
	if n % 2 == 0: 
		return False
	for i in xrange(3, int(n**0.5) + 1, 2): 
		if n % i == 0: 
			return False
	return True

# def gcd(a, b): 
# 	while b != 0: 
# 		t = b
# 		b = a % b 
# 		a = t
# 	return a

# def isCoprime(a, b): 
# 	return gcd(a, b) == 1

def findPrimeDivisors(n): 
	divisors = []
	for i in xrange(1, int(n**0.5) + 1): 
		if n % i == 0: 
			divisors.append(i)
			if float(i) != n ** 0.5:
				divisors.append(n / i)
	primeDivisors = filter(lambda x: isPrime(x), divisors)
	return primeDivisors

def totient(n):
	if n % 2 == 0:
		return 2 * totient(n / 2)
	product = n
	primeDivisor = findPrimeDivisors(n)
	for i in xrange(len(primeDivisor)): 
		product *= (1 - (1 / float(primeDivisor[i])))
	return int(product)

def R(d): 
	return totient(d) / float(d - 1)

d = 12
while R(d) > 15499 / float(94744): 
	print d , R(d)
	d += 1
print d, R(d)

### reducer approach
# import time
# t = time.time() 

# def isPrime(n): 
# 	# assert that n > 0 and n is integral
# 	if n < 2: 
# 		return False
# 	elif n <= 3: 
# 		return True
# 	for i in xrange(2, int(n ** 0.5) + 1): 
# 		if n % i == 0: 
# 			return False
# 	return True

# def countReducers(n): # excluding n and 1
# 	if isPrime(n): 
# 		return [] # later check if the length is 0
# 	divisor = []
# 	for i in xrange(2, int(n**0.5) + 1): 
# 		if n % i == 0: 
# 			divisor.append(i)
# 			if float(i) != n ** 0.5: 
# 				divisor.append(n/i)
# 	for i in xrange(len(divisor)): 
# 		multiple = divisor[i]
# 		while multiple < n: 
# 			divisor.append(multiple)
# 			multiple += divisor[i]
# 	reducer = list(set(divisor))
# 	return len(reducer)

# def R(d): 
# 	return (d - 1 - countReducers(d)) / float(d - 1)

# d = 5000000
# while R(d) > 15499 / float(94744): 
# 	print d, R(d)
# 	d += 1
# print d
# print "Finished in: " + str(time.time() - t) + " seconds."