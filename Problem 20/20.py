import math 
string = str(math.factorial(100))
accumulator = 0
for char in string: 
	accumulator += int(char)
print accumulator