import math, time
t = time.time()

S = 80
INF = 10000000
file = 'p082_matrix.txt'

with open(file,'r') as input:
	matrix = []
	for i in range(S): 
		matrix.append(map(int, input.readline().split(',')))

# m stores minimum costs from each square to ANY square in the rightmost column
m = [[INF for i in range(S)] for j in range(S)]

# we "edit" 3 times. It turns out that this is the magic number!
for j in range(3*S - 3, -1, -1): 
	for i in range(S): 
		if int(math.ceil(j/3)) == S - 1: 
			m[i][int(math.ceil(j/3))] = matrix[i][int(math.ceil(j/3))]
			continue
		else: 
			# start by assuming that optimal path is directly to the right, then edit
			m[i][int(math.ceil(j/3))] = matrix[i][int(math.ceil(j/3))] + m[i][int(math.ceil(j/3)) + 1]

		if i == 0: 
			m[i][int(math.ceil(j/3))] = matrix[i][int(math.ceil(j/3))] + min(m[i][int(math.ceil(j/3))+1], m[i+1][int(math.ceil(j/3))])
			continue
		if i == S - 1: 
			m[i][int(math.ceil(j/3))] = matrix[i][int(math.ceil(j/3))] + min(m[i][int(math.ceil(j/3))+1], m[i-1][int(math.ceil(j/3))])
			continue
		m[i][int(math.ceil(j/3))] = matrix[i][int(math.ceil(j/3))] + min(m[i][int(math.ceil(j/3))+1], m[i+1][int(math.ceil(j/3))], m[i-1][int(math.ceil(j/3))])


minPathSum = 100000000

for x in m: 
	if x[0] < minPathSum:
		minPathSum = x[0]

print minPathSum, "Execution time:", time.time() - t, "seconds."



		


