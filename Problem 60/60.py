prime = [1] * 1001
primeList = []

def isPrime(n): 
	if n == 2 or n == 3 or n == 5 or n == 7: 
		return True
	elif n < 11: 
		return False
	if n % 2 == 0: 
		return False

	for i in range(3, int(n ** 0.5) + 1, 2): 
		if n % i == 0:
			return False
	else: 
		return True

def genPrime(): 
	prime[0] = prime[1] = 0 
	for i in range(len(prime)): 
		if prime[i] == 1: 
			for j in range(2, (len(prime) - 1) // i): 
				prime[i * j] = 0
	prime[len(prime) - 1] = prime[len(prime) - 2] = 0

genPrime()

for i in range(len(prime)): 
	if prime[i]: 
		primeList.append(i)

print (primeList)
print (len(primeList))

for i in range(len(primeList)): 
	if not isPrime(primeList[i]): 
		print (i)

print primeList.find(i)
