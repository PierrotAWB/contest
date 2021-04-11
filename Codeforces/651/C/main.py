import math

t = int(input())

def isPrime(x):
    if x < 2 or x % 2 == 0:
        return False
    if x == 3 or x == 5 or x == 7:
        return True
    for i in range(3, int(x**0.5)+1, 2):
        if x % i == 0:
            return False
    return True

def isPow2(n):
    i = 1
    while 2 ** i <= n:
        if 2 ** i == n:
            return True
        i += 1
    return False

for i in range(t):
    n = int(input())
    #print(isPrime(n))
    if n == 1:
        print("FastestFinger")
    elif n % 2 == 1:
        print("Ashishgup")

    # even cases
    elif n == 2:
        print("Ashishgup")
    elif isPow2(n) or isPrime(int(n / 2)):
        print("FastestFinger")
    else:
        print("Ashishgup")
