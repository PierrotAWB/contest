import math, time # for floor function in approximation step 
t = time.time()

def gcd(a, b):
    while b != 0:
       t = b 
       b = a % b; 
       a = t 
    return a

def findNeighbour(): 
	minimum = 1
	target = 3 / float(7)

	for d in [x for x in xrange(1000000) if x != 7]:
		n = int(math.floor(target * d)) # numerator s.t. n/d is as close to 3/7 as possible
		if gcd(n,d) == 1 and target - n / float(d) < minimum: 
			minimum = target - n / float(d)
			num = n
			den = d
	return minimum, num, den

print findNeighbour()
print time.time() - t
