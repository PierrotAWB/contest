s = raw_input() 
k = int(raw_input())

def lexiCMP(str1, str2): # is str1 lexicographically (strictly) less than to str2?
	# assert the strings are lowercase and of equal length
	for i in xrange(len(str1)): 
		if ord(str1[i]) < ord(str2[i]): 
			return True
		elif ord(str1[i]) > ord(str2[i]): 
			return False
		else: 
			continue

minStr = "z" * k

for i in xrange(0, len(s) - k + 1):
	if lexiCMP(s[i:i + k], minStr) == True: 
		minStr = s[i:i+k]

print minStr