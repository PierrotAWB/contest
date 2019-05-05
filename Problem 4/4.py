# A palindromic number reads the same both ways. The largest palindrome 
# made from the product of two 2-digit numbers is 9009 = 91 x 99.
# Find the largest palindrome made from the product of two 3-digit numbers.
# 2016-12-29

# determine whether a number is a palindrome.
def isPalindromic(n):
	string  = str(n)
	for i in range(0, len(string) / 2):
		if string[i] != string[len(string) - 1 - i]:
			return False
	else:
		return True

palindrome = []

# find the largest palindrome as the product of two numbers
# both within a specified range
def findLargestPalindrome(low, high):
	for i in range(low, high):
		# WLOG, assume j >= i. This eliminates half of the products to be 
		# checked
		for j in range(i, high):
			if isPalindromic(i * j):
				palindrome.append(i * j)
	return max(palindrome)

print findLargestPalindrome(100, 1000)





