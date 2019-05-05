N = int(input())
accum = 0

s = list(input())

currentS = ['0']

for i in s:
	if i.isdigit(): 
		currentS.append(i)
	else:
		currentS.pop()

	accum += int("".join(currentS))

print(accum)