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

import time, math
from decimal import *



it = time.time()
t = 0
UPPER_BOUND = 333333
# {s, s, s + 1}
for s in range(2, UPPER_BOUND+1):
	getcontext().prec = 15
 	se = Decimal(1.5)*s + Decimal(0.5)
 	if s == 302828: 
 		getcontext().prec = 30
 		print (se*(se - s)*(se - s)*(se - s - 1))**0.5

 	if ((se*(se - s)*(se - s)*(se - s - 1))**0.5) % 1.0 == 0.0:
 		t += 2*se
 		print s, s, s+1

 	se -= 1

 	if ((se*(se - s)*(se - s)*(se - s + 1))**0.5) % 1.0 == 0.0:
 		t += 2*se
 		print s, s, s-1
print t, time.time() - it

# shorter = 5 #(two of them)

# if ((shorter+1) * ((3*shorter+1)*(shorter-1)) ** 0.5) % 4 == 0:
# 	print ((shorter+1) * ((3*shorter+1)*(shorter-1)) ** 0.5) / float(4), 3*shorter + 1
# else: 
# 	print "non-integral"

# if ((shorter-1) * ((3*shorter-1)*(shorter+1)) ** 0.5) % 4 == 0:
# 	print ((shorter-1) * ((3*shorter-1)*(shorter+1)) ** 0.5) / float(4), 3*shorter - 1
# else: 
# 	print "non-integral"


# 1080838249033
# 1081921351635

348453


