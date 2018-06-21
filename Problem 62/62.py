from time import time
t = time()
cubes, checked, partnerCount = {}, {}, {}
for i in xrange(1, 10000): 
	cubes[i] = i ** 3
	checked[i] = False
	partnerCount[i] = 0

for i in xrange(1, len(cubes)): 
	partnerCounter = 0 
	partner = [i] # store into memory the partners to turn checked into true
	j = i + 1

	if checked[i] == False: 
		while len(str(cubes[j])) == len(str(cubes[i])) and j < len(cubes): # count partners 
			if "".join(sorted(str(cubes[j]))) == "".join(sorted(str(cubes[i]))): 
				partner.append(j)
				partnerCounter += 1
			j += 1

	for i in xrange(len(partner)): 
		checked.update({partner[i]:True})
		partnerCount.update({partner[i]:partnerCounter})

for i in xrange(1, len(partnerCount)): 
	if partnerCount[i] == 4: 
		print i ** 3
		break
print time() - t

