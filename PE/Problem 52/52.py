import time
t = time.time() 

def countDigits(n): 
	digitCounter = [0] * 10
	for i in xrange(len(str(n))):
		digitCounter[int(str(n)[i])] += 1
	return digitCounter
# stacked if ladders are slower than one-liners.
def satisfiesProperty(n): 
	if len(str(n)) != len(str(2*n)) or len(str(n)) != len(str(3*n)) or len(str(n)) != len(str(4*n)) or len(str(n)) != len(str(5*n)) or len(str(n)) != len(str(6*n)): 
		return False
	if countDigits(n) == countDigits(2*n) and countDigits(n) == countDigits(3*n) and countDigits(n) == countDigits(4*n) and countDigits(n) == countDigits(5*n) and countDigits(n) == countDigits(6*n): 
		return True
# main

i = 1 
found = False
while not found: 
	if satisfiesProperty(i): 
		found = True
	else: 
		i += 1
print i
print "Finished in: " + str(time.time() - t) + " seconds."