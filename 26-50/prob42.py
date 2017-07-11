import time
t = time.time()

with open('words.txt', 'r') as input:
	word = map(str, input.readline().split("\",\""))
	input.close()

def computeWordScore(string): 
	accumulator = 0
	for i in range(len(string)): 
		accumulator += ord(string[i]) - 64
	return accumulator

def isTriangle(n): 
	# quadratic formula approach is possible, 
	# seeing as the inputs won't be too large, an iterative approach will be used
	for i in xrange(0, int((2 * n) ** 0.5) + 1): 
		if 2 * n == i * (i + 1): 
			return True

	else: 
		return False

word[0] = word[0].replace("\"", "")
word[len(word) - 1] = word[len(word) - 1].replace("\"", "")

counter = 0
for i in xrange(0, len(word)): 
	if isTriangle(computeWordScore(word[i])):
		counter += 1
print counter
print "Finished in: " + str(time.time() - t) + " seconds."