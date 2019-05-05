import sys
l = ["A", "B", "C", "D", "E", "F", "G", "H", "I", "J"]
for i in xrange(len(l) - 1):
	for j in xrange(9):
		for k in xrange(j + 1, j + 11):
			if k + 1 <= 9:
				sys.stdout.write(l[i] + str(k + 1) + '+')
			else:
				sys.stdout.write(l[i + 1] + str(k - 8) + '+')
		print ' ',
	print '\n'