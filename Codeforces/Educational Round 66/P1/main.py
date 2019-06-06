t = int(input())
for i in range(t):
	n, k = map(int, raw_input().split())
	count = 0
	while n != 0:
		r = n % k
		if r == 0:
			n /= k
			count += 1
		else: 
			n -= r
			count += r
	print count