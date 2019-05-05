
with open('cipher.txt', 'r') as input: 
	message = map(int, input.read().split(','))

#copy = list(message)
# create encryption keys
# key = [] 
# for i in xrange(97, 123): 
# 	for j in xrange(97, 123): 
# 		for k in xrange(97, 123):
# 			key.append([i, j, k])

# print key.index([103, 111, 100])
# print key[4422]
key = [103, 111, 100]
#print message[2]
# for i in xrange(0, len(key)): 
#message = copy
for i in xrange(len(message)): 
	message[i] = message[i] ^ key[(i + 1) % 3 - 1]

string = ""
for i in xrange(len(message)): 
	string += chr(message[i])

# if i == 4423:  
print string

accumulator = 0 
for i in xrange(len(string)): 
	accumulator += ord(string[i])

print accumulator


	#if string.find("(The Gospel of John, Chapter 5)") > 0:
	#		print i

#decode()

# 4422
# 4426
# 4430
# 4434
# 4438
# 4442
# 4498
# 4502
# 4506
# 4510
# 4514
# 4518
# 4522