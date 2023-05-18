M = int(10e9 + 7)

def solve():
    n, k = list(map( int, input().split(' ')))
    dp = [{} for _ in range(n)]

    arr = list(map(int, input().split(' ')))

    def b(x):
        return bin(x)[2:]

    dp[0][b(arr[0])] = 1

    for j in range(1, n):
        dp[j] = {b(arr[j]):1}

        for l in range(0, j):
            for key in dp[l]:
                res = b(int(key, 2) & arr[j])
                if res not in dp[j]:
                    dp[j][res] = 0
                dp[j][res] = (dp[j][res] + dp[l][key]) % M

    acc = 0
    for j in range(0, n):
        for key in dp[j]:
            if key.count('1') == k:
                acc = (acc + dp[j][key]) % M
    print(acc)

t = int(input())

for _ in range(t):
    solve()


"""
1
5 1
5 5 7 4 2
"""
