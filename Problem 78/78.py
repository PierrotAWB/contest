amount = 100000
coin = [i for i in range(1, amount + 1)]
ways = [0 for i in range(amount + 1)]
ways[0] = 1
for i in range(0, amount):
	for j in range(coin[i], amount + 1):
		ways[j] += ways[j - coin[i]]

for i in range(amount + 1): 
	if ways[i] % 1000000 == 0: 
		print "FOUND:", i