import time
t = time.time()

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

THRESHOLD = 50000000
MAX_PRIME = 7072

p = []
s = []; c = []; f = []
flag = [0 for i in range(THRESHOLD + 1)]

for i in range(1, MAX_PRIME+1): 
	if isPrime(i):
		p.append(i)

for prime in p: 
	if prime ** 2 <= THRESHOLD:
		s.append(prime ** 2)
	if prime ** 3 <= THRESHOLD:
		c.append(prime ** 3)
	if prime ** 4 <= THRESHOLD:
		f.append(prime ** 4)

for square in s: 
	for cube in c: 
		for fourth in f:
			if square + cube + fourth <= THRESHOLD:
				flag[square + cube + fourth] = 1

print flag.count(1), "Execution time:", time.time() - t, "seconds."

