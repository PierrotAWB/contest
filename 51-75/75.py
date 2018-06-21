# The most obvious brute force solutions to this problem
# are to either: 

# a) fix c and move in the range 5 to 1.5M
# all the while checking whether b = sqrt(c^2 - a^2) is an 
# integer. If it is, flag the sum a + b + c.
# This is clearly quadratic time complexity, which
# is far too much for a problem whose upper bound is 1.5M

# b) keep two counters a and b that increment in a nested
# fashion, keeping track of whether the sum of their squares
# is another perfect square (c^2). If so, flag the sum a + b + c.

# Finally, we would count the number of flags for each L, 
# and keep track of the number of times there is exactly one flag 
# for a particular L.

# Euclid's formula lends a better solution for generating primitive
# Pythagorean triples, though (ones in which gcd(a, b, c) = 1).

# let a = m^2 - n^2, b = 2mn, c = m^2 + n^2.

# Clearly, (a,b,c) is a Pythagorean triple, but it is quite
# remarkable that, provided m and n and coprime and not both odd, 
# this formula generates all possible primitive triples.

# After this, all we need to do is scale up these primitive triples
# and take their sum; i.e., if (a, b, c) is a Pythagorean triple,
# then so is (ka, kb, kc) for any positive integer k.

import time
ti = time.time() 

# constants
MAX_M = 900
MAX_L = 1500000

# global lists
primTriples = []
triples = []
flag = [0 for i in range(MAX_L + 1)]

if __name__ == "__main__":
	def gcd(a, b): 
		if b == 0: 
			return a
		else: 
			return gcd(b, a % b)

	# generate primitive Pythagorean triplets
	for m in range(1, MAX_M): 
		for n in range(1, m): 
			if m % 2 == 1 and n % 2 == 1: 
				continue
			if gcd(m, n) == 1: 
				if 2*m**2 + 2*m*n <= MAX_L:
					primTriples.append([int(m**2 - n**2), 2*m*n, int(m**2 + n**2)])

	# generate non-primitive Pythagorean triplets
	for t in primTriples:
		triples.append(t)
		i = 2
		while (i * sum(t) <= MAX_L):
			triples.append([i*t[0], i*t[1], i*t[2]])
			i += 1

	# flag all sums
	for t in triples: 
		flag[sum(t)] += 1

	# count the number of lengths, L, for which there is 
	# exactly one integer sided right triangle that can be
	# bent from a wire of length L
	res = 0
	for i in range(1, MAX_L+1):
		if flag[i] == 1:
			res += 1
	print res, "Execution time:", time.time() - ti, "seconds."















