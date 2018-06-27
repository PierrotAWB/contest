import time
t = time.time()
m = {}

UPPER_BOUND = 13000
MAX_K = 12000

def isPrime(n): 
	if n <= 7: 
		if n == 2 or n == 3 or n == 5 or n == 7: 
			return True
		return False
	if n % 2 == 0: 
		return False
	for i in range(3, int(n**0.5) + 1, 2): 
		if n % i == 0: 
			return False
	return True

# come up with the factorization of numbers up 
# to and including UPPER_BOUNDs
for i in range(2, UPPER_BOUND+1): 
	m[i] = []
	m[i].append([i])
	if isPrime(i): 
		continue
	for j in range(2, int(i**0.5) + 1):
		if i % j == 0:
			for k in m[i/j]:
				l = k + [j]
				m[i].append(sorted(l))

# determine whether i is a product-sum number of order k
def isProductSum(i, k):
	for j in m[i]: 
		if sum(j) + (k - len(j)) == i: 
			return True
	return False

minimalPSnum = set([])

for k in range(2, MAX_K+1):
	print k
	i = 2
	while True: 
		if isProductSum(i, k): 
			minimalPSnum.add(i)
			break
		i += 1
print sum(list(minimalPSnum)), time.time() - t












