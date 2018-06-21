import time
t = time.time() 

with open('matrix.txt', 'r') as input: 
	m1 = map(str, input.read().split('\n'))
	m1.pop()
	matrix = []

	for i in xrange(0, len(m1)): 
		matrix.append(map(int, m1[i].split(',')))
	input.close()

dimension = len(matrix) - 1
m = {(dimension, dimension):matrix[dimension][dimension]}

def minPathSum(matrix, i, j): 
	if (i, j) in m: 
		return m[(i, j)]
	if j == dimension: # right most column, add the minPath from node below
		if (i, dimension) not in m: # if the answer isn't in the memo table, put it in
			# m[(i, dimension)] = minPathSum(matrix, i, j)
			m[(i, j)] = matrix[i][j] + minPathSum(matrix, i + 1, j)
	elif i == dimension: # bottom most row, add the minPath from node to right
		if (dimension, j) not in m: 
			# m[(dimension, j)] = minPathSum(matrix, i, j)
			m[(i, j)] = matrix[i][j] + minPathSum(matrix, i, j + 1)
	else: 
		if (i, j) not in m: 
			# m[(i, j)] = minPathSum(matrix, i, j)
			m[(i, j)] = matrix[i][j] + min(minPathSum(matrix, i + 1, j), minPathSum(matrix, i, j + 1))
	return m[(i, j)] 

print minPathSum(matrix, 0, 0)
print "Finished in: " + str(time.time() - t) + " seconds."