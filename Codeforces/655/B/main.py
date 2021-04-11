t = int(input())

def isPrime(x):
    # Don't need to check even here
    if x == 3 or x == 5 or x == 7:
        return True
    for i in range(3, int(x**0.5)+1):
        if x % i == 0:
            return False
    return True

for i in range(t):
    n = int(input())
    if n % 2 == 0:
        print(str(int(n/2)) + " " + str(int(n/2)))
    elif isPrime(n):
        print(str(1) + " " + str(n - 1))
    else:
        d = 2
        while n % d != 0 and n > d ** 2:
            d += 1
        D = int(n / d)
        print(str(D) + " " + str(n - D))
        
