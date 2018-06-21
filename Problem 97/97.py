# create a rolling string that will get multiplied by 2 7830457 times
number = 2
for i in xrange(0, 7830456): 
	number *= 2
	if len(str(number)) > 10: 
		string = str(number)[-10:]
		number = int(string)

print number 

factor = 28433 
accumulator = 0

for i in xrange(len(str(factor)) - 1, -1, -1): 
	accumulator += int(str(int(str(factor)[i]) * number)[-1 * i + 4:]) * 10 ** (len(str(factor)) - 1 - i)

print int(str(accumulator)[-10:]) + 1
