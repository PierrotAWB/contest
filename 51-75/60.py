import time
t = time.time()

# we call a pair of primes "pairable"
# if we can concatenate them in any order
# and produce a prime number in both cases.

# we call a group of primes "absolutely pairable"
# if all the pairs of primes in the group are pairable.
def isPrime(n): 
	if n < 7: 
		if n == 2 or n == 3 or n == 5:
			return True
		else: 
			return False
	if n % 2 == 0: 
		return False
	for i in range(3, int(n**0.5)+1, 2):
		if n % i == 0: 
			return False
	return True

def isPairable(a, b):
	return isPrime(int(str(a) + str(b))) and isPrime(int(str(b) + str(a)))

def isInternallyPairable(a):
	for i in range(len(a)): 
		for j in range(i + 1, len(a)): 
			if isPairable(a[i], a[j]) == False:
				return False
	return True

# # return the index of x in m
# # if not found, return -1
# # assume m sorted
# def binarySearch(x, m):
# 	a = 0
# 	b = len(m) - 1
# 	while a <= b: 
# 		c = (a + b) / 2
# 		if x == m[c]: 
# 			return c
# 		elif x < m[c]:
# 			b = c - 1
# 		else: 
# 			a = c + 1
# 	return -1

# list of primes
l = []
for i in range(2, 10000): 
	if isPrime(i): 
		l.append(i)

p = [[] for i in range(6)]
for i in range(len(l)): 
	for j in range(i + 1, len(l)): 
		if isPairable(l[i], l[j]): 
			p[2].append([l[i], l[j]])

print len(p[2]), "pairs; generation completed in:", time.time() - t, "seconds."

for i in range(len(p[2])): 
	for j in range(len(l)): 
		if l[j] > p[2][i][-1]: 
			if isInternallyPairable(p[2][i] + [l[j]]): 
				p[3].append(p[2][i] + [l[j]])

print len(p[3]), "triplets; generation completed in:", time.time() - t, "seconds."

for i in range(len(p[3])): 
	for j in range(len(l)): 
		if l[j] > p[3][i][-1]: 
			if isInternallyPairable(p[3][i] + [l[j]]):
				p[4].append(p[3][i] + [l[j]])

print len(p[4]), "quadruplets; generation completed in:", time.time() - t, "seconds."

for i in range(len(p[4])): 
	for j in range(len(l)): 
		if l[j] > p[4][i][-1]: 
			if isInternallyPairable(p[4][i] + [l[j]]):
				p[5].append(p[4][i] + [l[j]])
				print p[4][i] + [l[j]], "Completed at time:", time.time() - t, "seconds. Sum:", sum(p[4][i] + [l[j]])

for i in range(len(p[5])):
	print p[5][i], sum(p[5][i])

print "DONE! Time:", time.time() - t






