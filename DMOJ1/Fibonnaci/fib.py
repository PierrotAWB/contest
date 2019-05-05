m = {0:1, 1:1}

def fib(n): 
	if n not in m: 
		m[n] = fib(n-1) + fib(n-2)
	return m[n]

N = int(raw_input())
print fib(N - 1) % 1000000007
