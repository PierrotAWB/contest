import math

def digitFactorial(n): 
	return sum(list(map(lambda x: math.factorial(int(x)), list(str(n)))))

NRChainLength = {} 

def findNRChainLength(n): # NR = non-repeating
	counter = 0; intermediaries = []
	while True: 
		if n in intermediaries: # a repetition has occured
			break
		intermediaries.append(n)
		n = digitFactorial(n)
	for i in xrange(len(intermediaries)): 
		NRChainLength[intermediaries[i]] = len(intermediaries) - i
	return len(intermediaries)

counter = 0
for i in xrange(1, 1000000):
	if i in NRChainLength: # this value has already been calculated
		if NRChainLength[i] == 60: 
			counter += 1 
			break
	length = findNRChainLength(i) # calculate the value and assign the other chain lengths
	if length == 60: 
		counter += 1

print counter


