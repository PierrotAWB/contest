q = int(input())
for i in range(q):
	n = int(input())
	moves = 0
	while n % 2 == 0 or n % 3 == 0 or n % 5 == 0:
		if n % 2 == 0:
			n /= 2
		elif n % 3 == 0:
			n = 2*n/3
		elif n % 5 == 0:
			n = 4*n/5
		moves += 1
	if n != 1:
		print -1
	else: 
		print moves