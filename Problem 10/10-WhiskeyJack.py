import time
t = time.time()
upper = 2*10**6
SIEVE = [1]*upper
d = 2
ans = 0
while d < upper:
    if SIEVE[d]:
        ans+=d
        for m in range(d*d,upper,d):
            SIEVE[m]=0
    d += 1 + d % 2

print(ans)
print(time.time() - t)

# 0.84500002861