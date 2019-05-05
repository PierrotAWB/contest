import time
t = time.time()  

def sumDigitSquared(n): 
	accumulator = 0
	for i in xrange(len(str(n))): 
		accumulator += int(str(n)[i]) ** 2
	return accumulator

m = {1:0, 2:1, 3:1}
def endsAt89(n): 
	term = n 
	while term != 1 and term != 89: 
		term = sumDigitSquared(term)
		if term in m: 
			if m[term] == 1: 
				return True
			else: 
				return False
		else: 
			m[term] = endsAt89(term)
	if term == 89: 
		return True
	else: 
		return False

# m = []
# for i in xrange(0, 567): 
# 	if endsAt89(i): 
# 		m[i] = True
# 	else: 
# 		m[i] = False

counter = 0
for i in xrange(1, 10000001): 
	if endsAt89(i): 
		counter += 1

print counter
print "Finished in: " + str(time.time() - t) + " seconds."