import time
t = time.time()

f = open("names.txt")
nameList = ["MARY"]

string = f.read()

for i in xrange(5, len(string)):
	word = ""
	if string[i:(i + 3)] == "\",\"":
		j = 3
		while string[i + j] != "\"":
			word += string[i + j]
			j += 1
		nameList.append(word)

nameList.sort()

def letterToNumber(letter):
	return ord(letter) - 64

def calculateNameScore(name):
	accumulator = 0
	for i in xrange(0, len(name)): 
		accumulator += letterToNumber(name[i])
	return accumulator

def main(): 
	accumulator = 0

	for i in xrange(0, len(nameList)): 
		accumulator += (i + 1) * calculateNameScore(nameList[i])

	return accumulator

print main()

print "Run time: " + str(time.time() - t) + " seconds"