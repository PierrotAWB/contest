n = int(input())
s = raw_input()
start = 0
# print s
while True:
	# print start
	acc = start
	for i in range(n):
		if s[i] == "-": 
			# print "Sub!"
			acc -= 1
		elif s[i] == "+":
			# print "Add!"
			acc +=1 
		if acc < 0:
			break

	if acc < 0:
		start += 1
	else:
		break
	
print acc