f, list = open("pyramid1.txt"), []
for line in f: 
	list.append(map(int, line.split()))
for i in xrange(15, 0, -1):
	for j in xrange(0, i - 1):
		list[i - 2][i - j - 2] += max(list[i - 1][i - j- 1], list[i - 1][i - j - 2])
print list[0]

