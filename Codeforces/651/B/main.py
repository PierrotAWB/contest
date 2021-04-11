t = int(input())

for i in range(t):
    n = int(input())
    l = list(map(int, input().split(' ')))
    for g in range(2, 1001):
        A = [[] for i in range(g)]
        for i, x in enumerate(l):
            A[x % g].append(i + 1)

        # Check if A works
        error = len(A[0]) % 2
        i = 1

        while i < g - i:
            error += abs(len(A[i]) - len(A[g - i]))

            if error > 2:
                break

            i += 1
        
        if error > 2:
            continue

        # A works; print out the steps
        count = 0

        for i in range(0, len(A[0]) - 1, 2):
            if count < 2*n - 2:
                print(A[0][i], A[0][i + 1])
                count += 2
            

        i = 1

        while i < g - i:
            for j in range(min(len(A[i]), len(A[g - i]))):
                if count < 2*n - 2:
                    print(A[i][j], A[g - i][j])
                    count += 2
            i += 1

        if g % 2 == 0:
            for i in range(0, len(A[(int)(g/2)])- 1, 2):
                if count < 2*n - 2:
                    print(A[(int)(g/2)][i], A[(int)(g/2)][i+1])
                    count += 2
        break

