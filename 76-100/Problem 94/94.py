# Heron's formula can be used to develop
# a fast test to see if an "almost equilateral"
# triangle has integral area.

# We exhaustively search up to s = 333 333 333.
# Note: there are two types of "almost equilateral"
# triangles, ones with two longer sides, or two shorter sides

# OPTIMIZATION: if a triangle {s, s, s + 1} has integral area
# then so does {ks, ks, ks + k}. Hence, if we determine a 
# "primitive" triple with integral area,
# any multiple of it works too. Thus, we need only check primes
# after which, we'll multiply. This is still difficult, because we
# would need to check primality on numbers of order 10^8 many times.

# Either way, we can modify a sieve to perform this: 
# if 

import time
it = time.time()
l = {}
UPPER_BOUND = 333333334
# {s, s, s + 1}
for s in range(2, UPPER_BOUND):
 	if s % 10000 == 0: 
 		print s
 	if s in l: continue
 	if ((s+1) * ((3*s+1)*(s-1)) ** 0.5) % 4 == 0:
 		l[s] = True
 		t = 2
 		while True:
 			if t*s < UPPER_BOUND:
 				l[t*s] = True
 				t += 1
 			else:
 				break

ans = 0
for side in l:
	ans += 3*side + 1

l.clear()

# {s, s, s - 1}
for s in range(2, UPPER_BOUND):
 	if s % 10000 == 0: 
 		print s
 	if s in l: continue
 	if ((s-1) * ((3*s-1)*(s+1)) ** 0.5) % 4 == 0:
 		l[s] = True
 		t = 2
 		while True:
 			if t*s < UPPER_BOUND:
 				l[t*s] = True
 				t += 1
 			else:
 				break

for side in l:
	ans += 3*side - 1

print ans, "Execution time:", time.time() - it, "seconds."
