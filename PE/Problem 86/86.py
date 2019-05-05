# Drawing out the net for the example cuboid reveals
# pretty quickly that the minimum distance, SF, is computed simply
# as the hypotenuse of a right triangle with sides 
# l and w + h. By convention, and without loss of generality, we will
# suppose that l >= w >= h. All cuboids can be oriented in such a way,
# and, all rotations are counted precisely once.

import math, time
t = time.time()

MAX_M = 2000
threshold = 1000000
n_sol = [0 for i in range(MAX_M + 1)]
for h in range(1, MAX_M): 
	print h
	for w in range(h, MAX_M): 
		for l in range(w, MAX_M): 
			if (l**2 + (w + h)**2)**0.5 % 1 == 0:
				for i in range(l, MAX_M + 1): 
					n_sol[i] += 1

print n_sol
for m in range(MAX_M): 
	if n_sol[m] > threshold: 
		print m, n_sol[m]
		break
	if m == MAX_M - 1:
		print "Not found!"

print time.time() - t

