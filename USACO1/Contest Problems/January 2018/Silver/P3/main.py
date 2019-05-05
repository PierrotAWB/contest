def numSuggested(v, k):
	count = 0
	for i in range(1, N + 1): 
		if (i != v):
			if rel[v][i] > k: 
				count += 1
	return count

def computeRelevances():
	for i in range(1, N + 1): # start nodes
		for node in l[i]: 
			

with open("mootube.in") as input: 
	a = input.readline().split()
	N = int(a[0]); Q = int(a[1])
	l = [[] for i in xrange(N + 1)]
	# create a matrix of relevances
	rel = [[] for i in xrange(N + 1)]
	for i in xrange(N - 1): 
		b = input.readline().split()
		p = int(b[0])
		q = int(b[1])
		r = int(b[2])
		l[p].append([q, r])
		l[q].append([p, r])
	with open("mootube.out", "w") as output:
		for i in xrange(Q): 
			c = input.readline().split()
			v = c[0]
			k = c[1]
			output.write(numSuggested(v, k))