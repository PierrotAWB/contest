with open('keylog.txt', 'r') as input: 
	keylog = [] 
	for line in input: 
		keylog.append(line)
	input.close()

for i in range(len(keylog)): 
	keylog[i] = keylog[i].replace('\n', '')

keylog = list(set(keylog))

preceedingNums = [[] for i in xrange(10)]


for i in xrange(len(keylog)): 
	for j in xrange(2, -1, -1):
		for k in xrange(0, j): 
			preceedingNums[int(keylog[i][j])].append(keylog[i][k])

for i in xrange(len(preceedingNums)): 
	preceedingNums[i] = list(set(preceedingNums[i]))

print preceedingNums