def countRectangles(l, w):
	n_rectangles = 0
	for i in range(1, w+1): 
		for j in range(1, l+1): 
			n_rectangles += (l - j + 1) * (w - i + 1)
	return n_rectangles

minDelta = 100000
area = 1
MAX_S = 90
for i in range(1, MAX_S): 
	for j in range(i, MAX_S):
		if abs(countRectangles(i, j) - 2000000) < minDelta: 
			minDelta = abs(countRectangles(i, j) - 2000000)
			area = i * j

print area

# Euler posted a very insightful analysis (adapted): 
# If you imagine a grid a cells wide by b cells tall (long?)
# you would have a + 1 vertical lines and b + 1 horizontal lines. 
# Any rectangle that could be picked from inside the rectangle
# would uniquely be defined by two of each. Hence, there
# are C(a + 1, 2) * C(b + 1, 2) = ab(a+1)(b+1)/4 rectangles.
# Now that our operation is essentially constant time, 
# we can be confident that we will produce an answer in a reasonable
# amount of time.