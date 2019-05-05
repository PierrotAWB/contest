N = int(input()) 
m = list(map(int, input().split(' ')))
for i in m: 
	if m.count(i) % 2 != 0: 
		print (i)
		break
