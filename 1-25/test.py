# list = [1, 2, 3, 4, 5]
# print ord('C')
# print chr(67)

# def numberToLetter(number): 
# 	return chr(int(number + 64))

# def letterToNumber(letter):
# 	return ord(letter) - 64

# print numberToLetter(3)
# print letterToNumber('C')

# list = ["a", "b", "\",\""]
# print list.index("\",\"")
# print "\",\""

# x = eval( '[' + open( 'names.txt' ).readlines()[ 0 ] + ']' )
# x.sort()

# print x

# def sumOfDivisors(n): 
# 	accumulator = 1
# 	for i in xrange(2, int(n ** 0.5) + 1):
# 		if n % i == 0: 
# 			accumulator += i
# 			accumulator += n / i 
# 	return accumulator

# print sumOfDivisors(945)

# markerList = [False] * 100
# print markerList

with open('pyramid1.txt', 'r') as input: 
	list1 = [int(x) for x in input.readline().split(' ')]
	list2 = [int(x) for x in input.readline().split(' ')]

print list1
print list2