from itertools import groupby
import time

# open file
with open('poker.txt', 'r') as input: 
	lineList = map(str, input.read().split('\n'))
	lineList.pop()
	h1, h1s, h2, h2s = [], [], [], []
	for line in lineList: 
		lh1 = []
		for i in xrange(0, 13, 3): 
			lh1.append(line[i])
		h1.append(lh1)

		lh1s = [] 
		for i in xrange(1, 14, 3): 
			lh1s.append(line[i])
		h1s.append(lh1s)

		lh2 = [] 
		for i in xrange(15, 28, 3):
			lh2.append(line[i])
		h2.append(lh2)

		lh2s = [] 
		for i in xrange(16, 29, 3): 
			lh2s.append(line[i])
		h2s.append(lh2s)
	input.close()

def convertAndSort(values): 
		table = {"T":"10", "J":"11", "Q":"12", "K":"13", "A":"14"}

		for i in xrange(len(values)): # convert letters to numbers
			if not values[i].isdigit():
				if values[i] in table: 
					values[i] = table[values[i]]

		num = [] #integer sort
		for i in xrange(len(values)): 
			num.append(int(values[i]))
		num.sort()

		for i in xrange(len(num)): 
			values[i] = str(num[i])
		return values

def determineStatus(values, suites): 

	def isStraight(values): 
		# assert that list values is sorted and converted
		for i in xrange(len(values) - 1): 
			if int(values[i]) + 1 != int(values[i + 1]):
				return False
		else: 
			return True

	def hasPair(values): 
		frequency = [len(list(group)) for key, group in groupby(values)]
		if 2 in frequency:
			return True
		else: 
			return False 
		
	# flush
	if len(set(suites)) == 1: 
		values = convertAndSort(values) 
		if isStraight(values) and values[0] == "10": # royal flush
			return 10
		elif isStraight(values): # straight flush
			return 9
		else: # flush
			return 6 
	elif isStraight(convertAndSort(values)): 
		return 5

	# multiplicities
	if len(set(values)) != len(values): 
		if len(set(values)) == len(values) - 1: # one pair
			return 2
		if len(set(values)) == len(values) - 2: # two pair or three of a kind
			values = convertAndSort(values)
			if hasPair(values): 
				return 3
			else: 
				return 4
		if len(set(values)) == len(values) - 3: # four of a kind or full house
			values = convertAndSort(values)
			if hasPair(values):
				return 7
			else: 
				return 8

	else: 
		return 1

def doesPlayer1Win(values1, suites1, values2, suites2): 

	def findGroup(values, size): # return the value of the bigger card (one that belongs to the group of specified size)
		# assert that list is sorted
		for i in xrange(len(values) - 1, -1, -1): 
			if values.count(values[i]) == size: 
				return values[i]

	def player1HasHighestCard(values1, values2): 
		if len(values1) == 1: 
			return int(values1[0]) > int(values2[0])
		# assert that the lists are sorted
		for i in xrange(len(values1) - 1, -1, -1): 
			if values1[i] != values2[i]: 
				return int(values1[i]) > int(values2[i])

	def stripRank(values): # remove all elements of multiplicity
		single = list(filter(lambda x: x * (values.count(x) <= 1), values))
		return single

	rank = determineStatus(values1, suites1)
	values1 = convertAndSort(values1); values2 = convertAndSort(values2)

	if determineStatus(values1, suites1) > determineStatus(values2, suites2): 
		return True
	elif determineStatus(values1, suites1) < determineStatus(values2, suites2): 
		return False
	elif determineStatus(values1, suites1) == determineStatus(values2, suites2):
		# parse the ranks
		if rank == 1:
			return player1HasHighestCard(values1, values2) 
		elif rank == 2: 
			if findGroup(values1, 2) > findGroup(values2, 2): 
				return True
			elif findGroup(values1, 2) < findGroup(values2, 2): 
				return False
			else: # equal
				values1 = stripRank(values1); values2 = stripRank(values2)
				return player1HasHighestCard(values1, values2)
		elif rank == 3: 
			# first check if a win can be determined with the higher pair
			if findGroup(values1, 2) > findGroup(values2, 2):
				return True
			elif findGroup(values1, 2) < findGroup(values2, 2):
				return False

			# remove the higher pair
			for i in xrange(len(values1) - 1, -1, -1): 
				if values1.count(values1[i]) == 2: 
					m = values1[i]
					for i in range(2): 
						values1.remove(m)
					break

			for i in xrange(len(values2) - 1, -1, -1): 
				if values2.count(values2[i]) == 2: 
					m = values2[i]
					for i in range(2): 
						values2.remove(m)
					break

			# check if a win can be determined from the lower pair
			if findGroup(values1, 2) > findGroup(values2, 2):
				return True
			elif findGroup(values1, 2) < findGroup(values2, 2):
				return False

			values1 = stripRank(values1); values2 = stripRank(values2)
			return player1HasHighestCard(values1, values2)
		elif rank == 4: 
			if findGroup(values1, 3) > findGroup(values2, 3): 
				return True
			elif findGroup(values1, 3) < findGroup(values2, 3): 
				return False
			else: 
				values1 = stripRank(values1); values2 = stripRank(values2)
				print values1, values2
				return player1HasHighestCard(values1, values2)
		elif rank == 5: 
			return player1HasHighestCard(values1, values2)
		elif rank == 6: 
			return player1HasHighestCard(values1, values2) 
		elif rank == 7: 
			if findGroup(values1, 3) > findGroup(values2, 3): 
				return True
			if findGroup(values1, 3) < findGroup(values2, 3): 
				return False
			# if this point has been reached the triples are tied.
			# Remove them then compare the pairs
			trip1 = findGroup(values1, 3); trip2 = findGroup(values2, 3)
			print trip1, trip2
			values1 = list(set(values1)); values2 = list(set(values2))
			values1.remove(trip1); values2.remove(trip2)
			return values1[0] > values2[0]
		elif rank == 8:  
			if findGroup(values1, 4) > findGroup(values2, 4): 
				return True
			elif findGroup(values1, 4) < findGroup(values2, 4):
				return False 
			else: 
				values1 = stripRank(values1); values2 = stripRank(values2)
				return player1HasHighestCard(values1, values2)
		elif rank == 9: 
			return player1HasHighestCard(values1, values2)
		elif rank == 10: 
			return player1HasHighestCard(values1, values2)

def main(): 
	counter = 0
	for i in xrange(len(h1)): 
		if doesPlayer1Win(h1[i], h1s[i], h2[i], h2s[i]) == True: 
			# print str(i + 1) + ": win"
			counter += 1

	return counter

print main()

print determineStatus(["T", "J", "Q", "K", "A"], ["H", "H", "H", "H", "H"])
print determineStatus(["5", "5", "5", "4", "4"], ["C", "S", "S", "D", "D"])

print doesPlayer1Win(["9", "7", "5", "4", "2"], ["D", "C", "S", "D", "C"], ["9", "7", "5", "4", "3"], ["C", "C", "D", "S", "D"])
# read player 1 and 2's hands one by one
	# store each player's hands in 2 different lists: 1 of val (string) and one of suit(string)
# determine rank (needs to be defined)
	# rankings must be defined
# decide whether player 1 or player 2 has one by rank
	# if tied, compare highest card
	# if still tied, compare next highest card, and so on
# each time player 1 wins, increment a counter