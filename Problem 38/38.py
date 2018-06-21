import time
t = time.time()
def calculateConcatenatedProduct(n, list): 
	string = ""
	for i in list: 
		string += str(n * i)
	return string
currentMax = 0
for i in xrange(2, 10):
	list = [a for a in xrange(1, i + 1)]
	# start at a reasonable place, e.g., for list = [1,2] starting at j = 1 is impractical
	j = 10 * (9 / i - 1)
	while len(calculateConcatenatedProduct(j, list)) <= 9: 
		if "".join(sorted(calculateConcatenatedProduct(j, list))) == "123456789" and calculateConcatenatedProduct(j, list) > currentMax: 
			currentMax = calculateConcatenatedProduct(j, list)
		j += 1
print currentMax 
print "Finished in: " + str(time.time() - t) + " seconds."
