import time
t = time.time()

def fib(n): 
	if n < 2: 
		return n 
	else: 
		return fib(n - 1) + fib(n - 2)

i = 1
while len(str(fib(i))) < 1000:
	i += 1

print i 
print "Run time: " + str(time.time() - t) + " seconds"
