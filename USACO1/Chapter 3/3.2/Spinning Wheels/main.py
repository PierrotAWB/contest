'''
ID: andreww7
LANG: PYTHON2
PROB: spin
'''
from fractions import gcd

def lcm(l):
	if len(l) == 2:
		return l[0]*l[1]/gcd(l[0], l[1])
	return lcm(l[0:1] + [lcm(l[1:])])

speed = []; wedge = [[] for i in range(5)]

def aligned():
	w = []
	for pair in wedge[0]: 
		w.append(pair)
	

def main():
	with open("spin.in", "r") as f:
		for i in range(5):
			l = list(map(int, next(f).split()))
			speed.append(l[0])
			for j in range(l[1]):
				wedge[i].append([l[2+2*j], l[2+2*j] + l[3+2*j]])
	f.close()
	M = lcm(speed)
	print M
	i = 0
	while (i < M):
		print i
		if aligned():
			break
		i += 1
		for j in range(5):
			for k in range(len(wedge[j])):
				wedge[j][k][0] = (wedge[j][k][0] + speed[j]) % 360
				wedge[j][k][1] = (wedge[j][k][1] + speed[j]) % 360

	with open("spin.out", "w") as output: 
		if i == M: 
			output.write('none\n')
			output.close()
			return
		output.write(str(i) + '\n')
		output.close()
				
main()