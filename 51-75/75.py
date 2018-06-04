# form Pythagorean triples
m = []
for c in range(5, 1000000):
	print c
	a = 1
	while (a < (c ** 2 - a ** 2) ** 0.5):
		b = (c ** 2 - a ** 2) ** 0.5
		if b % 1 == 0:
			t = [a, int(b), c]
			m.append(t)
		a += 1

print m

# add them and flag the appropriate sums

# count the number of indices flagged exactly once