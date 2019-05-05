import math, time
t = time.time()
# permutation generator

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

def isPandigital(N): 

	# if repeating digits already exist in N, automatically reject it
	marker = []
	for i in xrange(0, len(str(N))):
		marker.append(int(str(N)[i]))
	markerSet = set(marker)
	if len(marker) > len(markerSet):
		return False

	digitList = [1, 2, 3, 4, 5, 6, 7, 8, 9]
	stringNumber = str(N)

	# remove digits in digitList not part of the pandigital product
	for i in xrange(0, len(stringNumber)): 
		if int(stringNumber[i]) in digitList: 
			digitList.remove(int(stringNumber[i]))

	# create the arrangements of the remaining digits
	for i in xrange(1, math.factorial(len(digitList))):
		static = list(digitList)
		string = createPermutation(static, i) 

		for j in xrange(1, len(string)):
			if int(string[0:j]) * int(string[j:len(string)]) == N: 
				return True
	else: 
		return False

accumulator = 0

for i in xrange(10, 9877):
	if isPandigital(i) == True: 
		accumulator += i

print accumulator
print "Finished in: " + str(time.time()-t) + " seconds."
