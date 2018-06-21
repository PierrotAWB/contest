'''
This is a brute force approach.
We will exahustively search the 
search space of C(2600, 2) = 3 378 700
possible pairs of points, and 
check if the OQ dotted with OP produces
0. Note: we have to be very careful with what we 
define as Q and P. Without loss of generality
we'll assume that Q is at (x1, y1), while
P is at (x2, y2). Further, we'll
say that y1 <= y2. In other words,
P will always be as least as high up as Q. 
This will allow us to check each pairing exactly once.
'''

# a trick that you might use is to abandon the
# x-y plane and simply lable the points:
# start at the origin with zero, then sweep right.
# at the end of a line, continue at the left of the 
# line above. A pair x, y, would be calcaulated by 
# taking div and mod of the label with the
# side length + 1
import time
t = time.time() 

MAX_COORD = 50

def isRight(x1, y1, x2, y2):
	# if same point, or linearly dependent, 
	# dot product will be zero, but we can't accept degenerate triangles.
	if x1 == x2 and y1 == y2: 
		return False
	OQx = x1; OQy = y1
	OPx = x2; OPy = y2
	PQx = x2 - x1; PQy = y2 - y1
	return OQx * PQx + OQy * PQy == 0 or OPx * OQx + OPy * OQy == 0 or OPx * PQx + OPy * PQy == 0

ans = 0

# DEBUG
# print "(", x1, ",", y1,")", "(", x2, ",", y2,")"

# bottom row (x1 != 0)
for x1 in range(1, MAX_COORD + 1): 
	y1 = 0
	for x2 in range(MAX_COORD + 1): 
		for y2 in range(1, MAX_COORD + 1): 
			if isRight(x1, y1, x2, y2): 
				ans += 1

# rest of the rows (we can start with x1 = 0)
for x1 in range(MAX_COORD + 1): 
	for y1 in range(1, MAX_COORD + 1):
		for x2 in range(x1, MAX_COORD + 1):
			for y2 in range(1, MAX_COORD + 1):
				if isRight(x1, y1, x2, y2): 
					ans += 1

print ans, "Execution time:", time.time() - t, "seconds."
