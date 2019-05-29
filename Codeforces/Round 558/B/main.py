from collections import Counter

n = int(input())
l = list(map(int, raw_input().split()))
m = {}
for e in l:
	try: 
		m[e] += 1
	except: 
		m[e] = 1

# Determine whether it's possible to remove exactly one day from 
# A[1..x-1] and satisfy the given condition
def pos(x):
	ck = len(set(Counter(m).keys())); cv = len(set(Counter(m).values()))
	if cv > 2:
		return False
	if ck == 1:
		return True
	elif cv == 1 and min(m.values()) == 1:
		return True
	# All colours have the same frequency, except one, which has frequency 1
	elif cv == 2 and m.values().count(min(m.values())) == 1 and min(m.values()) == 1:
		return True
	elif cv == 2 and m.values().count(max(m.values())) == 1 and max(m.values()) - min(m.values()) == 1:
		return True
	return False

for x in range(n-1, -1, -1):
	if pos(x):
		print x + 1
		break
	if m[l[x]] > 1:
		m[l[x]] -= 1	
	else:
		del m[l[x]]