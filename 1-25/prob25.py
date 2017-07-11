memo = [1, 1]
def fib(n):
	if n <= len(memo): 
		return memo[n - 1]
	if n <= 2: 
		f = 1
	else: 
		f = fib(n-1) + fib(n-2)
		memo[n - 1] = f
	return f

print fib(12)
