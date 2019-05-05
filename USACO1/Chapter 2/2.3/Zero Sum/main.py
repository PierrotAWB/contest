"""
TASK: zerosum
LANG: PYTHON2
"""

import itertools

l = []
ans = []

with open("zerosum.in") as input: 
	n = int(input.readline())
	input.close()

a = list(itertools.product(["-", "+", " "], repeat=n-1))

for i in range(len(a)):
	s = ""
	for j in range(1, n):
		s += str(j) + a[i][j -1]
	s += str(n)
	l.append(s)

def removeSpaces(s):
	a = ""
	for i in range(len(s)):
		if s[i] != " ":
			a += s[i]
	return a

for exp in l: 
	if eval(removeSpaces(exp)) == 0:
		ans.append(exp)

ans = sorted(ans)

with open("zerosum.out", "w") as output:
	for x in ans:
		output.write(x + "\n")
	output.close()

