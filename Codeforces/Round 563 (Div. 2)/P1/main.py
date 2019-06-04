n = int(input())
l = list(map(int, raw_input().split()))
l = sorted(l)
if sum(l[:n]) != sum(l[n:]):
	print " ".join(map(str, l))
else: 
	print -1