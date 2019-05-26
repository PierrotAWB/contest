n, a, x, b, y = map(int, raw_input().split())
d = a
v = b
meet = False
while (d != x and v != y):
	d = (d + 1)%n
	v = (v - 1)%n
	if v == 0:
		v += n
	if v == d:
		meet = True
		break
	if d == x or v == y:
		break
if meet == True:
	print "YES"
else: 
	print "NO"