import math, time
t = time.time()

with open("largest_exponential.txt", 'r') as input: 
	rawLine = []
	for line in input: 
		rawLine.append(line)
	input.close()

pair = [[] for i in xrange(len(rawLine))]

for i in xrange(len(rawLine)): 
	num1, num2 = rawLine[i].strip("\n").split(",")
	pair[i].append(int(num1)); pair[i].append(int(num2))

def findLength(base, exponent): 
	return exponent * math.log(base, 10)

maxLen = 0
for i in xrange(len(pair)): 
	if findLength(pair[i][0], pair[i][1]) > maxLen: 
		maxLen = findLength(pair[i][0], pair[i][1])
		lineNum = i + 1 

print maxLen, lineNum
print "[Finished in " + str(time.time() - t) + "s]"


