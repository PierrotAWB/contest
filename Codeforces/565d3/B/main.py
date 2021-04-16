t = int(input())
for i in range(t):
	n = int(input())
	l = list(map(int, raw_input().split()))
	one = 0; two = 0; three = 0;
	for j in range(n):
		if l[j] % 3 == 0:
			three += 1
		if l[j] % 3 == 1:
			one += 1
		if l[j] % 3 == 2:
			two += 1
	print three + min(one, two) + (max(one, two) - min(one, two)) // 3