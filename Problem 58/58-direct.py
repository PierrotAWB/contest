import time
t = time.time()

def isPrime(n): 
	if n == 3: 
		return True
	for i in xrange(2, int(n ** 0.5) + 1): 
		if n % i == 0: 
			return False
	else: 
		return True

PRIME_PERCENT = 10
n = 3; prime_count = 0 
while True:
    for i in (1, 2, 3):
        prime_count += isPrime( n*n - i*(n-1))
    ratio = (100 * prime_count) / (2*n - 1)
    if ratio < PRIME_PERCENT: break
    n += 2
print n

print "Finished in: " + str(time.time() - t) + " seconds."