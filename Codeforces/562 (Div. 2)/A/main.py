n, a, x, b, y = map(int, raw_input().split())
d = a
v = b
meet = False
while (d != x and v != y):
	d += 1
	v -= 1
	if v == 0:
		v = n
	if d == n + 1:
		d = 1
	if v == d:
		meet = True
		break
	if d == x or v == y:
		break
if meet == True:
	print "YES"
else: 
	print "NO"