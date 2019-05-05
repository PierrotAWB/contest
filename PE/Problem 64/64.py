# executes in about 7.5 seconds
import math, time

t = time.time()

# Euclidean algorithm
def gcd(a, b):
	if b == 0: 
		return a
	else: 
		return gcd(b, a % b)

# check if there are smaller periods contained inside a
# for instance, [1,1,1,1,6,1,1,1,1,6,1,1,1,1,6] contains [1,1,1,1,6]
def isSelfSimilar(a): 
	# check if subsegments of a of equal length, i, can form list a
	# and are all equal to each other
	for i in range(1, len(a)/2+1):
		if len(a) % i != 0: 
			continue
		b = a[:i]

		# if the segments of length i don't match with a
		# then it is unknown whether a is self-similar; further 
		# testing is required: so continue in the outer for loop
		skip = False
		for j in range(1, len(a)/i): 
			if a[j*i:(j+1)*i] != b: 
				skip = True
				break
		if skip == True:
			continue
		# if still in loop, every single one of the i length 
		# subsegments matched with a, so a must be "self-similar"
		return True
	return False

# These can be tuned to optimize the solution
# ensure that MAX_ITERATIONS is at least twice MAX_PERIOD
MAX_ITERATIONS = 325
MAX_PERIOD = 160

def contFrac(N): 
	l = []
	r = int(math.floor(N ** 0.5))
	l.append(r)
	coeff = []
	a = 1; b = N; c = r
	iterations = 0
	while True:
		# rationalize the denominator
		d = b - c ** 2

		# simplify the fraction
		g = gcd(a, d)
		a /= g
		d /= g

		# take the next coefficient
		e = int(math.floor(a * (b ** 0.5 + c)/(float)(d)))
		c = abs(c - e * d)

		# reciprocate
		a = d

		coeff.append(e)
		'''
		in order to check for periods such as (1,1,1,1,6), 
		we must assume an upper bound and check after.
		In other words, it is not always correct to check if
		coeff is symmetrical about its half; this would incorrecrly
		stop execution in the example (1,1,1,1,6) after (1,1).
		if coeff[:len(coeff)/2] == coeff[len(coeff)/2:]:
		'''
		if iterations == MAX_ITERATIONS:
			break
		iterations += 1
	p = []
	for i in range(1, MAX_PERIOD): 
		if coeff[:i] == coeff[i:2 * i]: 
			if isSelfSimilar(coeff[:i]) == False:
				p = coeff[:i]
	l.append(p)
	return l

count = 0
for i in range(1, 10001): 
	if i ** 0.5 % 1 == 0: 
		continue
	l = contFrac(i)
	if len(l[1]) % 2 != 0: 
		count += 1
print count
print "Execution time:", time.time()-t, "seconds."












