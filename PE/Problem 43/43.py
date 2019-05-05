import math, time
t = time.time()

digitList = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

def createPermutation(numberList, permutationIndex):

	digit = []
	k = len(numberList)
	# numberList = [i for i in xrange(1, n + 1)] # n numbers, 1 to n

	total = permutationIndex - 1 # "nth permutation"

	for i in xrange(k - 1, -1, -1):
  		digit.append(numberList[total // math.factorial(i)])
		numberList.remove(digit[k - i - 1])
		total = total % math.factorial(i)
	 
	string = ""

	for i in xrange(0, len(digit)): 
		string += str(digit[i]) 

	return string

def isPrime(n): 
	if n == 2 or n == 3: 
		return True
	for i in xrange(2, int(n ** 0.5) + 1): 
		if n % i == 0: 
			return False
			break
	else: 
		return True

primeList = []
for i in xrange(2, 18): 
	if isPrime(i): 
		primeList.append(i)

# experiment with the speed of the if ladder (using ands? or using ifs with breaks?)

def satisfiesSubstringProperties(string): 
	for i in xrange(1, 8):
		if int(string[i:i + 3]) % primeList[i - 1] != 0: 
			return False
			break

	else: 
		return True

solution = []
for i in xrange(1, math.factorial(len(digitList)) + 1): 
	digit = list(digitList)
	currentPermutation = createPermutation(digit, i)
	if satisfiesSubstringProperties(currentPermutation) == True: 
		solution.append(int(currentPermutation))

print sum(solution)
print "Finished in: " + str(time.time() - t) + " seconds."