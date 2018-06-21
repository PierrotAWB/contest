# A Pythagorean triplet is a set of three natural numbers, 
# a < b < c, for which,

# a^2 + b^2 = c^2
# For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product abc.

# 2016-12-29

for c in range (3, 997):
	for a in range (1, c - 1):
		if a < (c ** 2 - a ** 2) ** 0.5:
			b = (c ** 2 - a ** 2) ** 0.5

		# test if c^2 can be expressed as the sum of two squares

		if c ** 2 == (a ** 2 + b ** 2) and a + b + c == 1000:
			print a, b, c, a * b * c

# this can be improved by reducing the number of cases to be checked