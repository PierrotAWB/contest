import math
n = int(input())
m = {}
for i in range(n): 
	s = raw_input()
	try: 
		m[s[0]] += 1
	except: 
		m[s[0]] = 1
count = 0

def c2(n): 
	return n*(n-1)/2.0

for key in m:
	count += c2(int(math.ceil(m[key] / 2.0))) + c2(int(math.floor(m[key] / 2.0)))

print int(count)
