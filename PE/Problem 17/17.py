import inflect, time
t, p = time.time(), inflect.engine()
letterAccumulator = 0

def countLetters(n):

	counter = 0

	string = p.number_to_words(n)
	for i in xrange(0, len(string)):	
		if string[i] != "," and string[i] != " " and string[i] != "-":
			counter += 1
	return counter

for i in xrange(1, 1001):
	letterAccumulator += countLetters(i)

print letterAccumulator

print time.time() - t