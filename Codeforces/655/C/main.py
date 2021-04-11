t = int(input())
for i in range(t):
    n = int(input())
    l = list(map(int, input().split(' ')))

    A = [0]
    inPlace = l[0] == 1
    for i in range(1, n):
        if l[i] == i + 1 and not inPlace:
            A.append(i)
            inPlace = True
        elif l[i] != i + 1 and inPlace:
            A.append(i)
            inPlace = False
  
    if l[A[-1]] == A[-1] + 1:
        t = len(A) - 1       
    elif len(A) == 1 and A[0] != 1:
        t = 2
    else:
        t = len(A)
        
    c = max(t - 1, 0)

    #print(A)
    print(c)
            
