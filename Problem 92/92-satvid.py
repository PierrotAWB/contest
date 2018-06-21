import time
t = time.time() 

def SquareSum(n):
    k = 0
    while n:
        m = n % 10
        n = n/10
        k = k + m*m
    return k

def Compute(ndigits):
    def Recurse(n):
        if not d.has_key(n):
            d[n] = Recurse(SquareSum(n))
        return d[n]
    max = 10**ndigits
    d = {1:1, 89:89}
    for i in range(1, 9*9*ndigits+1):
        Recurse(i)
    count = {1:0, 89:0}
    ss = {}
    us = {}
    sums = {}
    for i in range(0,10):
        ss[i] = i * i
        us[i] = 1
        sums[i*i] = i
    
    m = 10
    while m < max:
        vs = us.keys()
        lus = us.copy()
        for i in range(1, 10):
            n = i * m
            for v in vs:
                k = ss[i] + ss[v]
                if not sums.has_key(k):
                    sums[k] = n + v
                    us[n+v] = lus[v]
                    ss[n+v] = k
                else:
                    us[sums[k]] = us[sums[k]] + lus[v]
        m = m * 10
    del us[0]
    for i,n in us.items():
        k = d[ss[i]]
        count[k] = count[k] + n
    return count[89]

accumulator = 0 
for i in xrange(1, 8): 
    accumulator += Compute(i)

print accumulator 
print "Finished in: " + str(time.time() - t) + " seconds."

