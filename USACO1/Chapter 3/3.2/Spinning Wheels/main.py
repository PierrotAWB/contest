from fractions import gcd

def lcm(l):
	if len(l) == 2:
		return l[0]*l[1]/gcd(l[0], l[1])
	return lcm(l[0:1] + [lcm(l[1:])])

speed = []; wedge = [[] for i in range(5)]

def aligned():
	b = [0 for i in range(360)]
	for i in range(5):
		for pair in wedge[i]:
			j = pair[0]	
			while (j != (pair[1] + 1) % 360):
				b[j] += 1
				j = (j + 1) % 360
	return b.count(5) > 0


def main():
	with open("spin.in", "r") as f:
		for i in range(5):
			l = list(map(int, next(f).split()))
			speed.append(l[0])
			for j in range(l[1]):
				wedge[i].append([l[2+2*j], l[3+2*j]])
	f.close()
	M = lcm(speed)
	i = 0
	while (i < M):
		if aligned():
			break
		i += 1
		for j in range(5):
			for k in range(len(wedge[j])):
				wedge[j][k][0] = (wedge[j][k][0] + speed[j]) % 360
				wedge[j][k][1] = (wedge[j][k][1] + speed[j]) % 360
		print i, wedge

	with open("spin.out", "w") as output: 
		if i == M: 
			output.write('none\n')
			output.close()
			return
		output.write(str(i) + '\n')
		output.close()
				
main()