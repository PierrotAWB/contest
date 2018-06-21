import math, time
t = time.time() 

def gcd(a, b): 
	if b == 0: 
		return a
	else:
		return gcd(b, a % b)

maxD = 12000
res = 0
# 5 is the first denominator that for which there exists
# a numerator that puts the fraction in the target range
for i in range(5, maxD+1):
	m = int(math.floor(i/3))
	n = int(math.ceil(i/2))
	for j in range(m, n+1):
		if gcd(i, j) == 1:
			if j/float(i) >= 1/float(3) and j/float(i) <= 1/float(2):
				res += 1

print res, "Execution time:", time.time() - t, "seconds."