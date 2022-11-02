t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split(' ')))
    s = input()

    d = {}
    ans = ""

    for j in range(n):
        if a[j] not in d:
            d[a[j]] = s[j]
        else:
            if d[a[j]] != s[j]:
                ans = "NO"
                break
        if j == n - 1:
            ans = "YES"

    print(ans)

