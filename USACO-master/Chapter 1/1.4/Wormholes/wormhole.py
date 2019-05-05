import itertools, math

coordinate = []

with open("wormhole.in", "r") as input: 
	N = int(input.readline())
	for i in range(N):
		x, y = map(int, input.readline().split())
		coordinate.append([x, y])
	
# generate pairings
ID = []
for i in range(0, N): 
	ID.append(i)

groupingSet = []
pairing = []

def generatePairings(candidates, pairing, index):
	if index == N / 2:
		groupingSet.append(pairing)

	candidates = sorted(candidates)

	a = candidates[0]
	candidates.remove[candidates[0]]

	RANGE = len(candidates)

	for i in range(1, RANGE):
		b = candidates[i]
		candidates.remove[b]

		pairing.append([a, b])
		generatePairings(candidates, pairing, index + 1)

		if candidates.empty(): 
			return

		candidates.append(b)
		candidates.remove(candidates[index])

generatePairings(ID, pairing, 0)
print(groupingSet)



