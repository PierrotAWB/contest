# this solution approximates the probabilities of landing on any particular
# square by simulating a game starting at GO that runs for R rolls.

import random, time
t = time.time()

DIE_VALUE = 4
R = 300000

currentSquare = 0
doubleCount = 0

# count the number of times landed on each of the 40 squares
square = [0 for i in range(40)]

# decks
CH = [i for i in range(1, 17)]
CC = [i for i in range(1, 17)]

def strFormat(n): 
	addZero = False
	if n < 10:
		addZero = True

	if addZero:
		return "0" + str(n)
	return str(n)

def isRailway(n):
	return str(n)[-1] == "5"

def isUtility(n): 
	return n == 12 or n == 28

def initCards():
	random.shuffle(CH, random=random.random)
	random.shuffle(CC, random=random.random)

def drawCC(currentSquare):
	if CC[0] == 1: 
		currentSquare = 0
	elif CC[0] == 2:
		currentSquare = 10
	t = CC[0]
	CC.remove(t)
	CC.append(t)
	return currentSquare

def drawCH(currentSquare):
	if CH[0] == 1:
		currentSquare = 0
	elif CH[0] == 2:
		currentSquare = 10
	elif CH[0] == 3: 
		currentSquare = 11
	elif CH[0] == 4:
		currentSquare = 24
	elif CH[0] == 5:
		currentSquare = 39
	elif CH[0] == 6:
		currentSquare = 5
	elif CH[0] == 7:
		if currentSquare == 7: 
			currentSquare = 15
		elif currentSquare == 22: 
			currentSquare = 25
		else: 
			currentSquare = 5
	elif CH[0] == 8:
		if currentSquare == 7: 
			currentSquare = 15
		elif currentSquare == 22: 
			currentSquare = 25
		else: 
			currentSquare = 5
	elif CH[0] == 9:
		if currentSquare == 7 or currentSquare == 36:
			currentSquare = 12
		else: 
			currentSquare = 28
	elif CH[0] == 10: 
		currentSquare = (currentSquare - 3) % 40
	t = CH[0]
	CH.remove(t)
	CH.append(t)
	return currentSquare

initCards()

for i in range(R): 
	#if i % 100000 == 0:
		#print i

	# roll
	a = random.randint(1, DIE_VALUE)
	b = random.randint(1, DIE_VALUE)
	if a == b: 
		doubleCount += 1
	else: 
		doubleCount = 0

	if doubleCount == 3: 
		currentSquare = 10
		# does the double counter get reset? 
		# rules not clear here.
		doubleCount = 0
		square[currentSquare] += 1
		continue

	currentSquare = (currentSquare + a + b) % 40

	# Community chest
	if currentSquare == 2 or currentSquare == 17 or currentSquare == 33:
		currentSquare = drawCC(currentSquare)

	# Chance
	if currentSquare == 7 or currentSquare == 22 or currentSquare == 36:
		currentSquare = drawCH(currentSquare)

	# G2J
	if currentSquare == 30: 
		currentSquare = 10

	square[currentSquare] += 1

for i in range(len(square)): 
	square[i] /= (float)(R)

ans = ""
squareCheck = square[:]
squareCheck = sorted(squareCheck, reverse = True)

print squareCheck
for i in range(3): 
	for j in range(len(square)): 
		if squareCheck[i] == square[j]:
			ans += strFormat(j)

print ans, "Executed in:", time.time() - t, "seconds."


