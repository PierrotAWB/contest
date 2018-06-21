import time
t = time.time()

def romanNumeral(N):
	ans = ""
	# thousands
	if N > 1000: 
		for i in range(N / 1000): 
			ans += "M"
	# hundreds
	if N > 100: 
		if int(str(N)[-3]) == 9: 
			ans += "CM"
		elif int(str(N)[-3]) == 4: 
			ans += "CD"
		elif int(str(N)[-3]) < 5:
			for i in range(int(str(N)[-3])): 
				ans += "C"
		else: 
			ans += "D"
			for i in range(int(str(N)[-3]) % 5): 
				ans += "C"
	# tens
	if N > 10: 
		if int(str(N)[-2]) == 9: 
			ans += "XC"
		elif int(str(N)[-2]) == 4: 
			ans += "XL"
		elif int(str(N)[-2]) < 5:
			for i in range(int(str(N)[-2])): 
				ans += "X"
		else: 
			ans += "L"
			for i in range(int(str(N)[-2]) % 5): 
				ans += "X"
	# ones
	if int(str(N)[-1]) == 9: 
		ans += "IX"
	elif int(str(N)[-1]) == 4: 
		ans += "IV"
	elif int(str(N)[-1]) < 5:
		for i in range(int(str(N)[-1])): 
			ans += "I"
	else: 
		ans += "V"
		for i in range(int(str(N)[-1]) % 5): 
			ans += "I"
	return ans

with open("p089_roman.txt", 'r') as input:
	original = list(map(str, input.read().split()))
	input.close()

key = {}
key["M"] = 1000; key["D"] = 500; key["C"] = 100;
key["L"] = 50; key["X"] = 10; key["V"] = 5; key["I"] = 1;

number = []
minimal = []

# read in the numbers from the non-minimal list

skip = False

for i in range(len(original)): 
	value = 0
	for j in range(len(original[i])):
		if skip:
			skip = False
			continue
		if j < len(original[i]) - 1:
			if key[original[i][j]] < key[original[i][j + 1]]:
				value += key[original[i][j + 1]] - key[original[i][j]]
				skip = True
				continue
		value += key[original[i][j]]
	if i == 3: 
		print original[i], value, romanNumeral(value)
	number.append(value)

# convert the numbers to minimal form
for i in number:
	minimal.append(romanNumeral(i))

diff = 0
for i in range(len(original)): 
	if len(original[i]) - len(minimal[i]) < 0: 
		print "WEIRD"
	diff += len(original[i]) - len(minimal[i])

print diff, "Execution time:", time.time() - t, "seconds."










