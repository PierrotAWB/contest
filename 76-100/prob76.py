import math

p = {1:0, 2:1, 3:2}

# def maximumSearch(n, distance): # return the number of intermediate partitions from n to n + distance
# 	for i in xrange(1, int(math.ceil(n/2))): 


# def partitions(N): 
# 	if N in p: 
# 		return p[N]
# 	else: 
# 		partitionCounter = 0
# 		half = int(math.ceil(N / float(2)))
		
# 		for i in xrange(half, N): 
# 			partitionCounter += partitions(N - i) + 1

# 		for i in xrange(2, half): # i is the starting number of a chain
# 			accumulator = 1
# 			for j in xrange(1, ((N - i) - i - 1) + 1): # for as many j's as there are numbers from i to N exclusive, subtract out invalid chains
# 				accumulator += partitions(j) + 1
# 			partitionCounter += partitions(N - i) + 1 - accumulator
		
# 		partitionCounter += 1

# 		p[N] = partitionCounter
# 		return p[N]
	
# for i in xrange(1, 18): 
# 	print partitions(i) + 1, 

def partitions(N): 
	accumulator = 0 
	
	def tuple(2, N): # return the number of tuples that add to N
		return int(math.floor(N / float(2)))

	