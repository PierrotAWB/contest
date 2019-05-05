def isLeapYear(n):
	if n % 4 == 0: 
		if n % 100 == 0: 
			if n % 400 == 0: 
				return True
			else: 
				return False
		else: 
			return True 

addends = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
counter = 0
accumulator = 0

for i in xrange(1901, 2001):
	for j in xrange(0, 12):
		if j == 1 and isLeapYear(i) == True: 
			accumulator += addends[j] + 1
		else: 
			accumulator += addends[j]
		if accumulator % 7 == 5: 
			counter += 1

print counter  


