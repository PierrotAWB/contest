import itertools

triangle = []
square = []
pentagonal = []
hexagonal = []
heptagonal = []
octagonal = []

for i in range(45, 141): 
	triangle.append(i * (i + 1) // 2)

for i in range(32, 100):
	square.append(i ** 2)

for i in range(26, 82): 
	pentagonal.append(i * (3 * i - 1) // 2)

for i in range(23, 71):
	hexagonal.append(i * (2 * i - 1))

for i in range(21, 64):
	heptagonal.append(i * (5 * i - 3) // 2)

for i in range(19, 59): 
	octagonal.append(i * (3 * i - 2))

def cycleContinue(n1, n2):
# does n1->n2 form a valid cycle?
# i.e., are the last 2 dig's of n1 == last 2 dig's of n2?
	return str(n1)[-2:] == str(n2)[:2]

figurateList = [triangle, square, pentagonal, hexagonal, heptagonal, octagonal]
permutationList = list(itertools.permutations(figurateList, 6))

cycleList = []

def hasCycle(permutation): # list of 6 lists
	for i in range(len(permutation)): 
		for j in range(len(permutation[i])):
			for x in permutation[i + 1]: 
				if cycleContinue(permutation[i][j], x):
					return (permutation[i][j], x)

for permutation in permutationList: 
	print (hasCycle(permutation))


		