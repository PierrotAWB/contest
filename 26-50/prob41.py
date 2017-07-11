import math

# permutation generator
def createPermutation(numberList, permutationIndex):
	digit = []
	k = len(numberList)
	total = permutationIndex - 1 
	for i in xrange(k - 1, -1, -1):
  		digit.append(numberList[total // math.factorial(i)])
		numberList.remove(digit[k - i - 1])
		total = total % math.factorial(i)
	string = ""
	for i in xrange(0, len(digit)): 
		string += str(digit[i])
	return string

# primality test
def isPrime(n): 
	for i in xrange(2, int(n**0.5) + 1): 
		if n % i == 0: 
			return False
			break
	else: 
		return True

currentMaximum = 0
for i in xrange(4, 10):
	digitList = [a for a in xrange(1, i + 1)]
	for j in xrange(1, math.factorial(i) + 1):
		digit = list(digitList)
		currentPermutation = int(createPermutation(digit, j))
		if isPrime(currentPermutation) and currentPermutation > currentMaximum:
			currentMaximum = currentPermutation

print currentMaximum
