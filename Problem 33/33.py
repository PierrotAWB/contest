def isDigitCancelling(e, f):
	# e and f are two digit numbers
	if e >= f: 
		return False
 	a = list(set(str(e)))
 	b = list(set(str(f)))
 	overlap = [x for x in a if x in b]
 	if len(overlap) == 0: 
 		return False
	# reject trivial cases
	if str(e)[1] == "0" and str(f)[1] == "0":
		return False

	for i in xrange(0, len(str(e))): 
		for j in xrange(0, len(str(f))): 
			Etemp = str(e)
			Etemp = Etemp.replace(str(e)[i], '', 1)
			Ftemp = str(f)
			Ftemp = Ftemp.replace(str(f)[j], '', 1)
			if Etemp != "0" and Ftemp != "0":
				if int(Etemp) / float(Ftemp) == e / float(f):	
					return True
					break
	else: 
		return False
		
numerator = [10 * a + b for a in xrange(1, 10) for b in xrange(0, 10)]
denominator = [10 * c + d for c in xrange(1, 10) for d in xrange(0, 10)]
for i in numerator: 
	for j in denominator:
		if isDigitCancelling(i, j) == True:
			print str(i) + " / " + str(j)
