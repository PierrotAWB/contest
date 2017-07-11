import time
t = time.time()

# which is faster: checking if it's in the list? or adding all, then removing extras?

##### Removing extras (converting to a set) is approx. 40 times faster at the sample 
##### size

combination = []

for a in xrange(2, 101):
	for b in xrange(2, 101):
		combination.append(a ** b)

sequence = set(combination)
print len(sequence)

# combination = []

# for a in xrange(2, 101): 
# 	for b in xrange(2, 101):
# 		if a ** b not in combination: 
# 			combination.append(a ** b)

# print len(combination)

print time.time() - t