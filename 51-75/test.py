# import itertools, time
from string import maketrans

# def determineReplacements(n): 
# 	testNumber = str(n) # "56003"
# 	string = "" 
# 	for a in range(len(str(n))): 
# 		string += str(a)
# 	index = []
# 	for i in xrange(1, len(string)): 
# 		index.append(list(itertools.combinations((i for i in range(len(string))), i)))
# 	# using combinatoric identities, replacement as a 2D array can be generated as follows: 
# 	# replacements = [[] for i in xrange(2 ** len(string) - 2)]
# 	# data is harder to store this way, though. It is more efficient to structure
# 	# the replacement array in the same way as the index array (3D).
# 	replacements = [[[] for j in xrange(len(index[i]))] for i in xrange(len(index))]

# 	for i in xrange(0, len(index)):
# 		for j in xrange(0, len(index[i])):
# 			intab = ""
# 			for k in xrange(0, len(index[i][j])): 
# 				intab += str(testNumber[int(string[index[i][j][k]])])
# 			for a in xrange(1, 10): 
# 				outtab = str(a) * len(intab)
# 				translationTable = maketrans(intab, outtab)
# 				replacements[i][j].append(int(testNumber.translate(translationTable)))

# 	return replacements

# print determineReplacements(56003)
		# print "\n"

# str.translate(table[, deletechars])

#    Return a copy of the string where all characters occurring in the
#    optional argument *deletechars* are removed, and the remaining
#    characters have been mapped throu  gh the given translation table,
#    which must be a string of length 256.

#    You can use the "maketrans()" helper function in the "string"
#    module to create a translation table. For string objects, set the
#    *table* argument to "None" for translations that only delete
#    characters:

#    >>> 'read this short text'.translate(None, 'aeiou')
#    'rd ths shrt txt'

#    New in version 2.6: Support for a "None" *table* argument.

#    *s* where all characters have been mapped through the given
#    codec using the "codecs" module (see "encodings.cp1251" for an
#    example).

# m = {(1, 2):3, (3,4):5}
# print m

# def solution(number):
#       return sum(map(lambda x: x * (x % 3 == 0 or x % 5 == 0), [i for i in xrange(number + 1)]))

# print solution(1000)

# list = ['1', '2', 'A', '6']
# print list
# list.sort()
# print list

# list = [1, 1, 1, 2, 2]
# print list.count(1)

# for i in xrange(0, 0): 
# 	print i

# intab = "1"
# outtab = " "
# trantable = maketrans(intab, outtab)

# list = ["1", "1", "1", "2", "2"]
# list = list.translate(trantable)
# print list

# print (4, 3) > (6, 2)

# string = "987654321"
# string2 = "".join(sorted(string))
# print string2