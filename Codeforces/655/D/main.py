n = int(input())
A = list(map(int, input().split(' ')))

best = -1
index = -1
score = [0 for i in range(n)]

for i in range(0, len(A)):
    score[i] = A[i - 1] + A[(i + 1) % len(A)] - A[i]
    if score[i] > best:
        best = score[i]
        index = i

#print(A, score, best, index)

while len(A) > 1:
    A[index] = A[index - 1] + A[(index + 1) % len(A)]
    l = min((index + 1) % len(A), (index - 1) % len(A))
    r = max((index + 1) % len(A), (index - 1) % len(A))

    A.pop(r)
    A.pop(l)

    score.pop(r)
    score.pop(l)

    if (len(A) == 1):
        break

    score[index] = A[index - 1] + A[(index + 1) % len(A)] - A[index]
    score[index - 1] = A[index] + A[index - 2] - A[index - 1]
    score[(index + 1) % len(A)] = A[index] + A[(index + 2) % len(A)] - A[(index + 1) % len(A)]

    for i in range(0, len(A)):
        if score[i] > best:
            best = score[i]
            index = i

    #print(A, score, best, index)

print(A[0])

