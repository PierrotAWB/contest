import math 

# initialize

numberList = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
total = 999999
string = ""
digit = []

print total

for i in xrange(9, -1, -1):
  digit.append(numberList[total // math.factorial(i)])
  print math.factorial(i), numberList, total // math.factorial(i), numberList[total // math.factorial(i)]
  numberList.remove(digit[9 - i])
  total = total % math.factorial(i)
  print total
  
  
for i in xrange(0, len(digit)):
  string += str(digit[i])
  
print string