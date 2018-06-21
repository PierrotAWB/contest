counter = 0

for a in xrange(0, 2): 
	for b in [x for x in xrange(0, (200 - 200 * a) / 100 + 1)]:
		for c in [x for x in xrange(0, (200 - - 200 * a - 100 * b) / 50 + 1)]:
			for d in [x for x in xrange(0, (200 - 200 * a - 100 * b - 50 * c) / 20 + 1)]:
				for e in [x for x in xrange(0, (200 - 200 * a - 100 * b - 50 * c - 20 * d) / 10 + 1)]: 
					for f in [x for x in xrange(0, (200 - 200 * a - 100 * b - 50 * c - 20 * d - 10 * e) / 5 + 1)]:
						for g in [x for x in xrange(0, (200 - 200 * a - 100 * b - 50 * c - 20 * d - 10 * e - 5 * f) / 2 + 1)]:
							for h in [x for x in xrange(0, (200 - 200 * a - 100 * b - 50 * c - 20 * d - 10 * e - 5 * f - 2 * g) + 1)]:

								if 200 * a + 100 * b + 50 * c + 20 * d + 10 * e + 5 * f + 2 * g + h == 200: 
									counter += 1

print counter