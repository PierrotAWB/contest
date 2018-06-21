import time
t = time.time()
def isPrime(n): 
	if n < 2: 
		return False
	elif n <= 3: 
		return True
	for i in xrange(2, int(n ** 0.5) + 1): 
		if n % i == 0: 
			return False
			break
	else: 
		return True

def isCircular(n):
	if isPrime(n) == False: 
		return False
	else: 
		for i in xrange(0, len(str(n))): 
			if isPrime(int(str(n)[i:len(str(n))] + str(n)[0:i])) == False:
				return False
		else: 
			return True

counter = 0

# unoptimized

for i in xrange(2, 1000000): 
	if isCircular(i) == True: 
		counter += 1

# optimization: if a prime is circular, then so are its rotations

# marker = [False] * 1000000

# for i in xrange(0, len(marker)): 
# 	if isCircular(i): 
# 		marker[i + 1] == True
# 		for j in xrange(0, len(str(i))): 
# 			marker[int(str(i)[j:len(str(i))] + str(i)[0:j])] == True

# for True in marker: 
# 	counter += 1

# optimization (idea): if a number is not circular, then its rotations are not circular

print counter
print "Finished in: " + str(time.time() - t) + " seconds."