# Longest Collatz sequence under 1 million 
# 2016-12-30

import time 
t = time.time()

# visited = [False] * 99999999

# generate the Collatz sequence that begins at the inputted number.
def generateCollatz(startingNumber):
	counter = 0

	while startingNumber != 1:
		if startingNumber % 2 == 0: 
			startingNumber /= 2
			
		else: 
			startingNumber = 3 * startingNumber + 1

		# visited[startingNumber - 2] = True
		counter += 1

	# if the starting number is reduced to 1, this is the last term;
	# it must also be counted.
	counter += 1

	return counter

# find the longest Collatz sequence that begins with a starting number
# between 1 and the specified upper bound, inclusive.
def findLongestCollatzChain(upperBound):

	maxChain = 0

	for i in range(0, upperBound + 1):
		# if visited[i] == False: 
			chainLength = generateCollatz(i + 1)
			if chainLength > maxChain: 
				maxChain = chainLength
				index = i + 1
	return index

print findLongestCollatzChain(999999)

print time.time() - t