"""
ID: andreww7
LANG: PYTHON2
TASK: maze1
"""

import Queue

INF = 4000

grid = [[] for i in range(205)]
adj = [[] for i in range(3801)]
visited = [False for i in range(3801)]
distance = [INF for i in range(3801)]

def process(s):
	l = []
	for c in s:
		if c != '\n':
			l.append(c)
	return l

def printGrid(H):
	for i in range(2*H+1):
		print "".join(grid[i])

def main(): 
	fin = open('maze1.in', 'r')
	fout = open('maze1.out', 'w')
	W, H = map(int, fin.readline().split())

	for i in range(2*H+1):
		grid[i] = process(fin.readline())

	for i in range(H): 
		for j in range(W):
			# right side is open
			try: 
				if grid[2*i + 1][2*j + 1 + 1] == ' ' and grid[2*i + 1][2*j + 1 + 2] == ' ':
					adj[W*i + j].append(W*i + j + 1)
			except: 
				pass

			# left side is open
			try: 	
				if grid[2*i + 1][2*j + 1 - 1] == ' ' and grid[2*i + 1][2*j + 1 - 2] == ' ':
					adj[W*i + j].append(W*i + j - 1)
			except: 
				pass

			# top is open
			try: 
				if grid[2*i + 1 - 1][2*j + 1] == ' ' and grid[2*i + 1 - 2][2*j + 1] == ' ':
					adj[W*i + j].append(W*(i - 1) + j)
			except: 
				pass	

			# bottom is open
			try:
				if grid[2*i + 1 + 1][2*j + 1] == ' ' and grid[2*i + 1 + 2][2*j + 1] == ' ':
					adj[W*i + j].append(W*(i + 1) + j)
			except: 
				pass

	# printGrid(H)
	# print adj[:30]
	# print grid

	exit = []

	for i in range(2*H+1):
		# left wall
		if grid[i][0] == ' ':
			exit.append(W*((i - 1)/2))
		# right wall
		if grid[i][2*W] == ' ':
			exit.append(W*((i + 1)/2) - 1)

	for j in range(2*W+1):
		# top wall
		if grid[0][j] == ' ':
			exit.append((j - 1)/2)
		# bottom wall
		if grid[2*H][j] == ' ':
			exit.append(W*(H-1) + (j + 1)/2 - 1)

	# if both exits are at the same corner, we should keep only one of the duplicate "exit" squares.	
	if exit[0] == exit[1]: 
		exit.remove(exit[1])

	q = Queue.Queue()
	for E in exit:
		distance[E] = 1
		q.put(E)
		while(not q.empty()):
			s = q.get()
			if visited[s]:
				continue
			visited[s] = True
			for u in adj[s]:
				q.put(u) 
				distance[u] = min(distance[u], distance[s] + 1)
			
		# reset visited array
		for i in range(3801):
			visited[i] = False

	fout.write(str(max(distance[:W*H])) + '\n')
	fout.close()

main()