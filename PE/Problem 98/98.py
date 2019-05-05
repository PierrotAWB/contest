# BIG IDEA: use buckets to store
# like objects (of same length)

# 14 is the length of the longest word in the dictionary
# 1 is the shortest

import time

t = time.time()

MAX_LENGTH = 14
MAX_PAIR_MEMBER_LENGTH = 9

with open("p098_words.txt", "r") as input:
	l = input.read().split(",")
	for i in range(len(l)):
		l[i] = l[i].strip('"')
	input.close()

w = [[] for i in range(MAX_LENGTH + 1)]
# revised array; contains elements who have 
# anagramic pairs
wp = [[] for i in range(MAX_LENGTH + 1)]

for i in range(len(l)):
	w[len(l[i])].append(l[i])

def isAnagram(a, b):
	return sorted(a) == sorted(b)

for i in range(1, MAX_LENGTH + 1):
	for j in range(len(w[i])):
		for k in range(j + 1, len(w[i])):
			if isAnagram(w[i][j], w[i][k]):
				wp[i].append([w[i][j], w[i][k]])

# sort squares of necessary length into buckets by length
sq = [[] for i in range(MAX_PAIR_MEMBER_LENGTH + 1)]
i = 4
while True:
	if len(str(i**2)) <= 9:
		sq[len(str(i**2))].append(i**2)
	else: 
		break
	i += 1

# for a given anagramic pair, check if there is 
# matching set of squares in sq

# NOTE: it is not explicitly stated in the problem
# but after cheking the forums, I've concluded that
# not only must different letters be represented by
# different numbers, but one letter must be mapped 
# to one number exactly. For instance, one can map the
# E's in "SHEET" and "THESE" to precisely one digit.

# NOTE: there might be more than one valid pairing.

anSq = []

def pushAnagramicSquarePairs(a, b):
	# define square and string as bijective if
	# each letter is mapped to exactly one number
	# and each number is mapped to exactly one letter
	def isBijective(square, s):
		m = {}
		# create a mapping of letters to numbers
		for i in range(len(s)):
			if s[i] not in m:
				m[s[i]] = []
			m[s[i]].append(int(str(square)[i]))
		# if any letter is mapped to more than one number,
		# return false immediately
		for i in range(len(s)):
			m[s[i]] = list(set(m[s[i]]))
			if len(m[s[i]]) > 1:
				return False
		# check whether any number has been mapped to more 
		# than one letter
		l = [0 for i in range(10)]
		for i in m:
			l[m[i][0]] += 1
			if l[m[i][0]] >= 2:
				return False
		return True

	# convert b using the mapping given from a to square
	# we can assume this is possible, because this method
	# is called only if square and a are bijective
	def convert(a, b, square):
		m = {}
		for i in range(len(a)):
			m[a[i]] = int(str(square)[i])
		s = ""
		for i in range(len(b)):
			s += str(m[b[i]])
		return int(s)

	for i in range(len(sq[len(a)])):
		if isBijective(sq[len(a)][i], a): 
			if convert(a, b, sq[len(a)][i]) in sq[len(a)]:
				anSq.append(sq[len(a)][i])
				anSq.append(convert(a, b, sq[len(a)][i]))

if __name__ == "__main__": 
	for i in range(len(wp)):
		for j in range(len(wp[i])):
			pushAnagramicSquarePairs(wp[i][j][0], wp[i][j][1])

	print max(anSq), "Executed in:", time.time() - t, "seconds."





