coin = [1, 2, 5, 10, 20, 50, 100, 200]
amount = 200
ways = [0 for i in range(amount + 1)]
ways[0] = 1
for i in range(0, 8):
	for j in range(coin[i], amount + 1):
		ways[j] += ways[j - coin[i]]
	print ways, ""

print ways[amount]