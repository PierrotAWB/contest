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

def isDoublePalindromic(n): 
	if isPalindromic(str(n)) == False: 
		return False
	else: 
		string = str(bin(n))
		string = string.replace('0b', '', 1)
		if isPalindromic(string) == True: 
			return True

		else: 
			return False

accumulator = 0
for i in xrange(0, 100000000):
	if isDoublePalindromic(i) == True: 
		accumulator += i

print accumulator
print "Finished in: " + str(time.time() - t) + " seconds."