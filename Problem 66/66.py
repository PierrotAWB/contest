'''
It is quite marvelous that for positive integers p and q, and 
non-square n, p^2 - n*q^2 = 1 if, and only if, p/q is a convergent
of the simple continued fraction for sqrt(n).

Rather than attempt this problem in a brute-force manner (
trying different y's and finding a perfect square), we will use 
a method written for problem 64 used to find the simple continued 
fraction representation of irrational square roots.

For a commented version of the continued fraction methods, see 
problem 64.
'''
import math, time
t = time.time()

def gcd(a, b):
	if b == 0: 
		return a
	else: 
		return gcd(b, a % b)

def isSelfSimilar(a): 
	for i in range(1, len(a)/2+1):
		if len(a) % i != 0: 
			continue
		b = a[:i]
		skip = False
		for j in range(1, len(a)/i): 
			if a[j*i:(j+1)*i] != b: 
				skip = True
				break
		if skip == True:
			continue
		return True
	return False

MAX_ITERATIONS = 80

def contFrac(N): 
	l = []
	r = int(math.floor(N ** 0.5))
	l.append(r)
	coeff = []
	a = 1; b = N; c = r
	iterations = 0
	while True:
		d = b - c ** 2
		g = gcd(a, d)
		a /= g
		d /= g
		e = int(math.floor(a * (b ** 0.5 + c)/(float)(d)))
		c = abs(c - e * d)
		a = d
		coeff.append(e)
		if iterations == MAX_ITERATIONS:
			break
		iterations += 1

	# this bit is not needed in this problem; we don't care about
	# the period length
	# for i in range(1, MAX_PERIOD): 
	# 	if coeff[:i] == coeff[i:2 * i]: 
	# 		if isSelfSimilar(coeff[:i]) == False:
	# 			p = coeff[:i]
	l.append(coeff)
	return l

# find the a-th convergent of sqrt(n)
def convergent(a, n):
	l = contFrac(n)
	num = 1; den = l[1][a-1]
	for i in range(a - 1, 0, -1): 
		num = l[1][i-1] * den + num
		temp = num
		num = den
		den = temp
	num = l[0] * den + num
	return [num, den]

D = 1000
maxAns = 0
maxD = 0

for i in range(2, D+1):
	print i
	if i ** 0.5 % 1 == 0: 
		continue
	solutionFound = False
	j = 1
	while solutionFound == False:
		xy = convergent(j, i)
		if xy[0] ** 2 - i * xy[1] ** 2 == 1: 
			if xy[0] > maxAns: 
				maxAns = xy[0]
				maxD = i
			solutionFound = True
		j += 1

print "D =", maxD, "; x =", maxAns
print "Execution time:", time.time()-t, "seconds."












