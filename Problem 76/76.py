coin = [i for i in range(1, 100)]
amount = 100
ways = [0 for i in range(amount + 1)]
ways[0] = 1
for i in range(0, 99):
	for j in range(coin[i], amount + 1):
		ways[j] += ways[j - coin[i]]
print ways[amount]