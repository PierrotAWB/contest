def isPrime(n): 
	if n == 1: 
		return False
	if n == 2 or n == 3 or n == 5 or n == 7: 
		return True
	if n % 2 == 0: 
		return False
	for i in xrange(3, int(n ** 0.5) + 1, 2): 
		if n % i == 0: 
			return False
	return True

N = int(raw_input())

for i in xrange(N): 
	primeCounter = 0
	a, b = map(int, raw_input().split())
	for j in xrange(a, b): 
		if isPrime(j): 
			primeCounter += 1
			print j 
	print primeCounter

print isPrime(1)