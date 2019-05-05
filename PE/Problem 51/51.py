import time, itertools
from string import maketrans
t = time.time() 

def isPrime(n): 
	if n == 2 or n == 3: 
		return True
	for i in xrange(2, int(n**0.5) + 1):
		if n % i == 0: 
			return False
	return True

def determinePrimeReplacements(n): 
	testNumber = str(n) # "56003"
	string = "" 
	for a in range(len(str(n))): 
		string += str(a)
	index = []
	for i in xrange(1, len(string)): 
		index.append(list(itertools.combinations((i for i in range(len(string))), i)))
	# using combinatoric identities, replacement as a 2D array can be generated as follows: 
	# replacements = [[] for i in xrange(2 ** len(string) - 2)]
	# data is harder to store this way, though. It is more efficient to structure
	# the replacement array in the same way as the index array (3D).
	replacements = [[[] for j in xrange(len(index[i]))] for i in xrange(len(index))]

	for i in xrange(0, len(index)):
		for j in xrange(0, len(index[i])):
			intab = ""
			for k in xrange(0, len(index[i][j])): 
				intab += str(testNumber[int(string[index[i][j][k]])])
			for a in xrange(0, 10): 
				outtab = str(a) * len(intab)
				translationTable = maketrans(intab, outtab)
				replacements[i][j].append(int(testNumber.translate(translationTable)))

	# immediately remove all replacements that are not primes
	for i in xrange(len(replacements)): 
		for j in xrange(len(replacements[i])): 
			replacements[i][j] = list(filter(lambda x: isPrime(x) == True and len(str(x)) == len(str(n)), replacements[i][j]))
	return replacements

def determineMaxFamily(n): 
	replacements = determinePrimeReplacements(n)
	currentMaxFamily = 0
	for i in xrange(len(replacements)):
		if len(max(replacements[i], key = len)) > currentMaxFamily: 
			currentMaxFamily = len(max(replacements[i], key = len))
	return currentMaxFamily

# print determinePrimeReplacements(120383)

def main(): 
	# generate primelist
	prime = []
	for i in xrange(2, 1000000): 
		if isPrime(i): 
			prime.append(i)

	# set up the search in a while loop
	i = 0 
	found = False 
	while not found: 
		if determineMaxFamily(prime[i]) == 8:
			found = True
		else: 
			i += 1
	print prime[i]

main()

print "Finished in: " + str(time.time() - t) + " seconds."
