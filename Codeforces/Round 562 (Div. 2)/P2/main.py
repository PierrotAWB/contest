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

	intersection = []	
	i = 2
	if l[0][0] in l[1]:
		intersection.append(l[0][0])
	if l[0][1] in l[1]:
		intersection.append(l[0][1])
	while len(intersection) == 2 and i < m:
		for item in intersection:
			if item not in l[i]:
				intersection.remove(item)
		i += 1

	if len(intersection) == 0:
		print "NO"
		return

	if i == m:
		if l[0][0] in l[i-1] or l[0][1] in l[i-1]:
			print "YES"
			return
		print "NO"
		return
	
	if len(intersection) == 2:
		print "YES"
		return 

	# there's one item in the intersection, either it's x or y
	x = intersection[0] 
	j = i
	while j < m and x in l[j]:
		j += 1
	if j == m:
		print "YES"
		return
	y = l[j][0]
	if y > x:
		if contains(j, x, y):
			print "YES"
			return	
	y = l[j][1]
	if y > x:
		if contains(j, x, y):
			print "YES"
			return

	y = intersection[0]
	j = i
	while j < m and y in l[j]:
		j += 1
	if j == m:
		print "YES"
		return
	x = l[j][0]
	if y > x: 
		if contains(j, x, y):
			print "YES"
			return
	x = l[j][1]
	if y > x: 
		if contains(j, x, y):
			print "YES"
			return	

	print "NO"

main()