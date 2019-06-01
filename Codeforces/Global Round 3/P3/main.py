n = int(input())
p = [0] + list(map(int, raw_input().split()))
moves = []

for i in range(1, n+1):
	# already in place, continue
	if p[i] == i:
		continue
	ind = p.index(i)
	# far enough, swap directly in
	if abs(ind - i) >= n / 2:
		moves.append([ind, i])
		p[ind], p[i] = p[i], p[ind]
		continue
	# not far enough, pick furthest pivot point
	if n - ind > ind - 1:
		piv1 = n
	else:
		piv1 = 1
	# swap pivot and current
	moves.append([piv1, ind])
	p[piv1], p[ind] = p[ind], p[piv1]
	# one pivot sufficient
	if abs(i - piv1) >= n / 2:
		moves.append([i, piv1])
		p[i], p[piv1] = p[piv1], p[i]
		moves.append([piv1, ind])
		p[piv1], p[ind] = p[ind], p[piv1]
	# needs two pivots
	else: 
		if piv1 == 1:
			piv2 = n
		else: 
			piv2 = 1
		moves.append([piv1, piv2])
		p[piv1], p[piv2] = p[piv2], p[piv1]
		moves.append([piv2, i])
		p[piv2], p[i] = p[i], p[piv2]
		moves.append([piv1, piv2])
		p[piv1], p[piv2] = p[piv2], p[piv1]
		moves.append([piv1, ind])
		p[piv1], p[ind] = p[ind], p[piv1]

print len(moves)
for move in moves: 
	print str(move[0]) + " " + str(move[1])







