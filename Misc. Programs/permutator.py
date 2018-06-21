import math, time
# permutation generator
t = time.time()

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
		string += str(digit[i]) + " "

	return string

print "Finished in: " + str(time.time() - t) + " seconds"



