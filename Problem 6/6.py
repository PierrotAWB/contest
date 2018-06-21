# Find the difference between the sum of the
# squares of the first one hundred natural numbers 
# and the square of the sum.
# 2016=12=29

# by mathematical formulas
result = (100 * 101 / 2) ** 2 - (100 * 101 * 201 / 6)
print result

# by brute force
def sumUpTo(n): 
	accumulator = 0
	for i in range(1, n + 1):
		accumulator += i

	return accumulator

def sumOfSquaresUpTo(n):
	accumulator = 0
	for i in range(1, n + 1):
		accumulator += i ** 2

	return accumulator

print sumUpTo(100) ** 2 - sumOfSquaresUpTo(100)

