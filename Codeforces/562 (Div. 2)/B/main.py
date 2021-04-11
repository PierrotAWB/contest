l = []
n, m = map(int, raw_input().split())
	
for i in range(m):
	a, b = map(int, raw_input().split())
	l.append([a, b])

def contains(start, i, j):
	for k in range(start, m):
		if i not in l[k] and j not in l[k]:
			return False
	return True

def main():
	if m == 1:
		print "YES"
		return
	# l[0][0] is amongst x, y
	a = l[0][0]
	i = 1
	while i < m and a in l[i]:
		i += 1
	
	if i == m:
		print "YES"
		return

	if contains(i, a, l[i][0]) or contains(i, a, l[i][1]):
		print "YES"
		return

	#l[0][1] is amongst x, y
	b = l[0][1]
	i = 1
	while i < m and b in l[i]:
		i += 1
	
	if i == m:
		print "YES"
		return

	if contains(i, l[i][0], b) or contains(i, l[i][1], b):
		print "YES"
		return

	x = min(l[0]); y = max(l[0])
	if contains(0, x, y):
		print "YES"
		return

	print "NO"

main()