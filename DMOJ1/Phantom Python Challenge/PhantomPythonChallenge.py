#print ('\n'.join(s for s in map(lambda x: str(x), filter(lambda x: (x % 2 == 0), range(int(input())))))) 

# numList = []
# for i in range(50): 
# 	numList.append(i)

# prime = list(map(list, filter(lambda x, i: (x % i == 0 for i in range(2, int(50 ** 0.5) + 1)), numList)))
# print (prime)

# or x % i == 0 for i in range(3, int(x ** 0.5) + 1, 2)

#isPrime = lambda x: 0 if ((x%2==0 and x!=2)^x%i==0 for i in range(3,int(x**0.5)+1,2)) else 1

# a = lambda x: 0 if (x%2==0 and x!=2) else 1
# b = lambda x: 0 if (x % i == 0 for i in range(3, int(x**0.5)+1, 2)) else 1

# for i in range(2, 20): 
# 	print str(i) + ": ", b(i)
# n=int(input());l=[i for i in range(2,n+1)];p=[]
# while len(l)>0: 
# 	p.append(l[0]);l=[x for x in l if x%l[0]!=0]
# for i in p:
# 	print (str(i)+"*" if(i+2 in p or i-2 in p)else i)
# n=int(input())
# l=[i for i in range(n)]

# print filter(lambda n : n%2==0, (i for i in range(2, int(input())+1)))

import time
t = time.time()
l = [i for i in range(2, int(input()) + 1)]
l = filter(lambda: x)
print time.time() - t










