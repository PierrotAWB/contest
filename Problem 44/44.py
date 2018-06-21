import time
t = time.time()

def isPentagonal(n): 
	# set up quadratic and solve
	discriminant = (1 + 24 * n) ** 0.5
	if (1 + discriminant)/float(6) % 1 == 0  and (1 + discriminant)/float(6) > 0 or (1 - discriminant)/float(6) % 1 == 0 and (1 - discriminant)/float(6) > 0:
		return True, (1 + discriminant)/float(6), (1 - discriminant)/float(6)
	else: 
		return False

# generate list of pentagonal numbers
pentagonal = []
for i in xrange(1, 2500): 
	pentagonal.append((i * (3 * i - 1))/2)

# currentMinDiff = 100000000

# for i in xrange(0, len(pentagonal) - 1): 
# 	for j in xrange(i + 1, len(pentagonal)):
# 		print i
# 		if pentagonal[i] + pentagonal[j] in pentagonal and abs(pentagonal[i] - pentagonal[j]) in pentagonal:
# 			if abs(pentagonal[i] - pentagonal[j]) < currentMinDiff:
# 				currentMinDiff = abs(pentagonal[i] - pentagonal[j])

# print currentMinDiff

# currentMinDiff = 10000000000
# for i in xrange(0, len(pentagonal) - 1): 
# 	for j in xrange(i + 1, len(pentagonal)): 
# 		if isPentagonal(pentagonal[i] + pentagonal[j]): 
# 			if isPentagonal(2 * pentagonal[i] + pentagonal[j]):
# 				print str(pentagonal[i]) + " *" + str(pentagonal[j]) + "* " + str(pentagonal[i] + pentagonal[j]) + " " + str(2 * pentagonal[i] + pentagonal[j])
# 				if pentagonal[j] < currentMinDiff:
# 					currentMinDiff = pentagonal[j]
# 			elif isPentagonal(pentagonal[i] + 2 * pentagonal[j]):
# 				print "*" + str(pentagonal[i]) + "* " + str(pentagonal[j]) + " " + str(pentagonal[i] + pentagonal[j]) + " " + str(2 * pentagonal[i] + pentagonal[j])
# 				if pentagonal[i] < currentMinDiff: 
# 					currentMinDiff = pentagonal[i]

# print currentMinDiff


# print isPentagonal(1560090)
# print isPentagonal(5482660)
# print isPentagonal(7042750)
# print isPentagonal(8602840)

print time.time() - t
