from sympy import sieve

minD = 300000000
maxD = 1000000000
TARGET_RESILIENCE = 15499/94744
TOLERANCE = 0.025

#def isPrime(n):
#    if n == 2: 
#        return True
#    if n < 2 or n % 2 == 0:
#        return False
#    if n == 3 or n == 5 or n == 7:
#        return True
#    for i in range(3, int(n**0.5)+1):
#        if n % i == 0:
#            return False
#    return True
#
## Generate primes up to maxD
#primes = list(filter(isPrime, range(1, maxD+1)))
#divisors = [[] for i in range(maxD+1)]
#
#for prime in primes:
#    i = 1
#    while i * prime <= maxD:
#        divisors[i * prime].append(prime)
#        i += 1

L = list(sieve.totientrange(minD, maxD+1))
print("Completed sieve construction!")

for d, t in zip(range(minD, maxD+1), L):
    resilience = t/(d - 1) 
    # prod = reduce(lambda x, y: x*y, list(map(lambda a : 1 - 1/float(a), divisors[d]))) 

    if resilience < TARGET_RESILIENCE + TOLERANCE:
        print(d, resilience)
        if resilience < TARGET_RESILIENCE:
            print("Success!")
            break

