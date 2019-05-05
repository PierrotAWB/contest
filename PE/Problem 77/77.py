# We proceed by interpreting this as a variation
# on the coin problem, again (see Problem 31 and 76)
import time
t = time.time() 

l = []
def isPrime(n): 
	if n <= 7: 
		if n == 2 or n == 3 or n == 5 or n == 7: 
			return True
		return False
	if n % 2 == 0: 
		return False
	for i in range(3, int(n**0.5)+1, 2): 
		if n % i == 0: 
			return False
	return True

N = 1000
for i in range(N): 
	if isPrime(i): 
		l.append(i)
ways = [0 for i in range(N + 1)]
ways[0] = 1
for i in range(len(l)):
	for j in range(l[i], N+1):
		ways[j] += ways[j - l[i]]
i = 0
while ways[i] < 5000: 
	i += 1
print i, ways[i], "Execution time:", time.time() - t, "seconds."