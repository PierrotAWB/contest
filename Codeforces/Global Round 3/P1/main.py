a, b, c = map(int, raw_input().split())
one = 0
if a > b:
	one = 2*c + 2*b + 1
else: 
	one = 2*c + 2*a
two = 0
if b == 0:
	two = 0
else: 
	if a > b - 1:
		two = 1 + 2*c + b - 1 + b
	else: 
		two = 1 + 2*c + 2*a
print max(one, two)