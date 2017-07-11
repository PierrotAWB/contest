import time
t = time.time() 

def reverseString(string): 
	reverseString = "" 
	for i in xrange(len(string) - 1, -1, -1): 
		reverseString += string[i]
	return reverseString

def isPalindromic(string): 
	if reverseString(string) == string:
		return True
	return False

def reverseAndAdd(n): 
	return n + int(reverseString(str(n)))

def isLychrel(n): 
	# if within 50 iterations of reverseAndAdd on n no palindrome is yielded, return true
	counter = 0
	palindromic = False
	while not palindromic and counter < 51: 
		if not isPalindromic(str(reverseAndAdd(n))):
			n = reverseAndAdd(n)
		else: 
			palindromic = True
		counter += 1

	return counter >= 50

def main(): 
	counter = 0
	for i in xrange(1, 10001): 
		if isLychrel(i): 
			counter += 1
	print counter
	print "Finished in: " + str(time.time() - t) + " seconds."

main()

# optimization: since reverse and add is a commutable operation, if one number is not Lychrel
# its mirror won't be lychrel. E.g., 47 is not Lychrel so that 74 won't be either. 
# How do we skip over certain elements in an xrange, though? 

# ans: 249