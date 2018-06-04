import itertools, time
t = time.time()
l = [[] for i in range(9)]

for i in range(45, 141):
	l[3].append(i * (i + 1) / 2)
for i in range(32, 100): 
	l[4].append(i * i)
for i in range(26, 82): 
	l[5].append(i * (3 * i - 1) / 2)
for i in range(23, 71):
	l[6].append(i * (2 * i - 1))
for i in range(21, 64):
	l[7].append(i * (5 * i - 3) / 2)
for i in range(19, 59):
	l[8].append(i * (3 * i - 2))

octEnding = []
for i in range(40): 
	octEnding.append(str(l[8][i])[2:])

# a list of the possible orderings of the different figurate groups
orderings = list(itertools.permutations([3, 4, 5, 6, 7], 5))

# attempt to construct a 6-cycle figurate group with the given order
# if successful, halt the program, else continue.
def solve(ordering):
	# records of the different figurates
	# this is used to determine whether a given number should be considered
	ending = [[] for i in range(6)]
	beginning = []
	candidate = [[] for i in range(6)]

	# first go through one time: 
	# the method starts by drawing a circle out around the figurates,
	# it will arrive back at one of the octagonal numbers only if there was a path
	# this path, however is not actually narrowed down in this step.
	for i in range(len(l[ordering[0]])):
		if str(l[ordering[0]][i])[:2] in octEnding: 
			candidate[0].append(l[ordering[0]][i])
			ending[0].append(str(l[ordering[0]][i])[2:])
			beginning.append(str(l[ordering[0]][i])[:2])

	for i in range(1, 5):
		for j in range(len(l[ordering[i]])):
			if str(l[ordering[i]][j])[:2] in ending[i - 1]:
				candidate[i].append(l[ordering[i]][j])
				ending[i].append(str(l[ordering[i]][j])[2:])
		if len(candidate[i]) == 0: 
			return

	# here, we finalize the octagonal number that produced the successful circular path
	# generally, there is only one such number, so not much else needs to be done.
	for i in range(40): 
		if str(l[8][i])[:2] in ending[4] and str(l[8][i])[2:] in beginning:
			candidate[5].append(l[8][i])
			ending[5].append(str(l[8][i])[2:])

	# here we systematically filter the other figurate groups
	# based on our sole candidate for the octagonal number. 
	for i in range(0, 5): 
		candidate[i] = [x for x in candidate[i] if str(x)[:2] in ending[i - 1 if i > 0 else 5]]
		ending[i][:] = []
		for j in candidate[i]: 
			ending[i].append(str(j)[2:])
	candidate[5] = [x for x in candidate[5] if str(x)[:2] in ending[4]]

	# there should be only one member remaining in each family after the filtering process.
	if len(candidate[5]) == 1 and len(candidate[0]) == 1 and len(candidate[1]) == 1 and len(candidate[2]) == 1 and len(candidate[3]) == 1 and len(candidate[4]) == 1: 
		print ordering, candidate[5], candidate[0], candidate[1], candidate[2], candidate[3], candidate[4]
		print candidate[5][0] + candidate[0][0] + candidate[1][0] + candidate[2][0] + candidate[3][0] + candidate[4][0]
		print "Executed in:", time.time() - t, "seconds."

if __name__ == "__main__":
	for ordering in orderings:
		solve(ordering)


