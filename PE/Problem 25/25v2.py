m = {0: 1, 1: 1}
def fib(n):
    #assert n >= 0
    if n not in m:
        m[n] = fib(n-1) + fib(n-2)
    return m[n]

i = 0
while len(str(fib(i))) < 1000: 
	i += 1
print i + 1
