# Find the value of D <= 1000 in minimal solutions of x for which the largest value of x is obtained.
sqr = []
for i in range(1, 10000): 
	sqr.append(int(i**2))

def detMinX(D):
	# Lagrange showed that there are no integer solutions to x^2 - D*y^2 = 1 for square D's
	if D in sqr: 
		return 0

	found = False
	y = 1
	while (not found):
		if 1 + D * int(y ** 2) in sqr:
			return int((1 + D * y ** 2) ** 0.5)
			found = True
		y += 1

minX = [0]
for i in range(1, 1001):
	print i 
	minX.append(detMinX(i))
print max(minX)