n = int(input())
l = list(map(int, raw_input().split()))
m = [[] for i in range(n)]
# First index in m to insert
e = {4:0, 8:0, 15:0, 16:0, 23:0, 42:0}
editDistance = 0
prev = {8:4, 15:8, 16:15, 23:16, 42:23}

for i in range(editDistance, n):
	if l[i] == 4 or e[l[i]] < e[prev[l[i]]]:
		m[e[l[i]]].append(l[i])
		e[l[i]] += 1
	else: 
		editDistance += 1
for i in m:
	if len(i) != 6 or i != [4, 8, 15, 16, 23, 42]:
		editDistance += len(i)
print editDistance