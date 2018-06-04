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

# we need record to primes only up to the square root of the upper bound;
# if a number is composite, in the worst case you have a product of
# two similary sized primes (numbers like this are generally the "hardest"
# to factor).
l = []
for i in range(3163): 
	if isPrime(i): 
		l.append(i)

F = [[] for i in range(10000)]

# for our purposes (calculating phi(n)), we don't actually need exponents for 
# our prime factors. We care about only the primes that divide n.
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

if __name__ == "__main__":
	def phi(n): 
		ans = n
		f = factor(n)
		for prime in f:
			ans *= (1 - 1 / float(prime)) 
		return int(ans)

	def isPermutation(A, B): 
		A = str(A); B = str(B)
		a = []; b = []
		for char in A: 
			a.append(char)
		for char in B: 
			b.append(char)

		if len(a) != len(b): 
			return False
		a = sorted(a)
		b = sorted(b)
		for i in range(len(a)): 
			if a[i] != b[i]: 
				return False
		return True

	minRatio = 2
	for i in range(2, 10000000): 
		if i % 10000 == 0: 
			print i
		if isPermutation(phi(i), i): 
			if i / float(phi(i)) < minRatio:
				minRatio = i / float(phi(i))
				n = i

	print n, minRatio


