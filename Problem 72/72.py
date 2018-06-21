import time
t = time.time()

def isPrime(n): 
	if n <= 7: 
		if n == 2 or n == 3 or n == 5 or n == 7: 
			return True
		return False
	if n % 2 == 0: 
		return False
	for i in range(3, int(n ** 0.5) + 1, 2): 
		if n % i == 0: 
			return False
	return True

l = []
for i in range(3163): 
	if isPrime(i): 
		l.append(i)

def factor(n): 
	f = []
	if isPrime(n): 
		f.append(n)
		return f
	i = 0
	while n > 1: 
		if n % l[i] == 0: 
			f.append(l[i])
			while n % l[i] == 0: 
				n /= l[i]
		if isPrime(n): 
			f.append(n)
			return f
		i += 1
	return f

def phi(n): 
		ans = n
		f = factor(n)
		for prime in f:
			ans *= (1 - 1 / float(prime)) 
		return int(ans)

ans = 0
for i in range(2, 1000001):
	print i
	ans += phi(i)
print ans, "Execution time:", time.time() - t



