import time
t = time.time() 

def properDivisorSum(n):
	l = [1]
	for i in range(2, int(n ** 0.5) + 1):
		if n % i == 0:
			l.append(i); l.append(n / i)
	return sum(l)

pds = [0]
# these were calculated one time; the file loads into pds in 
# about half a second.
with open("pds.txt", "r") as input: 
	pds += list(map(int, input.read().split()))
	input.close()

visited = [0 for i in range(1000000)]
longestChain = []

MAX_LENGTH = 998

def dfs(s, u, chain):
	global currentChain
	currentChain = []
	if visited[s]:
		return
	# stop if element of chain exceeds 1M or if already visited
	if u > 1000000 or u == s:
		visited[s] = True
		if u != s: 
			return
		else: 
			chain.append(s)
			currentChain = chain[:]
			return
	# if first time, flag visited = true
	visited[u] = True
	if len(chain) < MAX_LENGTH:
		chain.append(u)
		u = pds[u]
		dfs(s, u, chain)
	else: 
		return

# # starting points
for i in range(1, 1000000): 
	if i % 1000 == 0: 
		print i
	dfs(i, pds[i], [])
	if len(currentChain) > len(longestChain):
		longestChain = currentChain[:]

print min(longestChain), "Execution time:", time.time() - t, "seconds."


