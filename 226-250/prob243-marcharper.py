import math, time
t = time.time()

def primes_up_to(n):
    # http://code.activestate.com/recipes/576640/
    nroot = int(math.sqrt(n))
    sieve = [True] * (n+1)# range(n+1)
    sieve[0] = False
    sieve[1] = False

    for i in range(2, nroot+1):
        if sieve[i]:
            m = n/i - i
            sieve[i*i: n+1:i] = [False] * (int(m)+1)

    return [i for i in range(n+1) if sieve[i]]

def multiple_gen(modulus):
    """Generates the list of multiples of modulus."""
    count = 1
    while True:
        yield modulus * count
        count += 1

def fast_compute_totients(bound):
    """Simultaneously compute totients for all numbers
    up to and including n."""
    # Populate the initial list with the leading factor of n.
    results = list(range(1, bound+1))
    # Get the list of primes up to the bound.
    primes = primes_up_to(bound)

    for p in primes:
        for m in multiple_gen(p):
            if m > bound:
                break
            results[m-1] = (results[m-1] / p) * (p - 1)
    print "totients generated" + str(time.time() - t)
    return results

if __name__ == '__main__':
    results = fast_compute_totients(5 * 10**7)
    for i in xrange(2, len(results) - 1): # i are the indices; i + 1 are the arguments denominators 
        if results[i] / float(i) < 15499 / float(94744):
            print i + 1
    print "Done in " + str(time.time() - t) + " seconds"