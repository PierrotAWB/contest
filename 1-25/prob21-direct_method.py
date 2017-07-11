import time 
t = time.time() 

def d(n): 
	accumulator = 1
	for i in xrange(2, int(n**0.5)+1): 
		if n % i == 0:
			accumulator += i
			accumulator += n / i		
	return accumulator

def isAmicable(n): 
	if n == d(d(n)) and n != d(n): 
		return True
	else: 
		return False

counter = 0

for i in xrange(1, 10000):
	if isAmicable(i) == True: 
		counter += i

print counter

print "Finished in: " + str(time.time() - t) + " seconds"
