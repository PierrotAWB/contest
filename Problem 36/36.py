import time
t = time.time()
def reverse(string):
	reverseString = "" 
	for i in xrange(len(str(string)) - 1, -1, -1):
		reverseString += string[i]
	return reverseString

def isPalindromic(string): 
	if reverse(string) == string: 
		return True
	else: 
		return False

def decimalToBinary(n):
	# initiate the string and repeated quotient
	string = ""
	quotient = n

	# divide through by two repeatedly for all the digits in the string
	while quotient / float(2) >= 0.5: 
		# if there is a remainder (of 1, most likely), append 1 to the string
		if quotient % 2 != 0: 
			string += "1" 
		# if the current quotient is evenly divided by 2, append 0 to the string
		else:
			string += "0"
		# divide the quotient by two (remove the 1/2; note that this is done automatically with integer division)
		quotient /= 2

	# reversse the string and return it
	return reverse(string)

def isDoublePalindromic(n): 
	if isPalindromic(str(n)) == False: 
		return False
	else: 
		if isPalindromic(decimalToBinary(n)) == True: 
			return True

		else: 
			return False

accumulator = 0
for i in xrange(0, 100000000):
	if isDoublePalindromic(i) == True: 
		accumulator += i

print accumulator
print "Finished in: " + str(time.time() - t) + " seconds."
