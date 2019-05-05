def isTriangle(n): 
	discriminant = 1 + 8 * n
	if (- 1 + discriminant ** 0.5)/float(2) % 1 == 0 and discriminant ** 0.5 - 1 > 0:
		return True
	else: 
		return False

def isPentagonal(n): 
	discriminant = (1 + 24 * n) ** 0.5
	if (1 + discriminant)/float(6) % 1 == 0  and (1 + discriminant)/float(6) > 0 or (1 - discriminant)/float(6) % 1 == 0 and (1 - discriminant)/float(6) > 0:
		return True
	else: 
		return False

def isHexagonal(n): 
	discriminant = 1 + 8 * n 
	if (1 + discriminant ** 0.5)/float(4) % 1 == 0 and discriminant ** 0.5 + 1 > 0: 
		return True
	else: 
		return False

def hexagon(n): 
	return n * (2 * n - 1)

print hexagon(143)
print hexagon(144)

i = 144
while isPentagonal(hexagon(i)) == False or isTriangle(hexagon(i)) == False: 
	i += 1

print i * (2*i - 1)


