from bisect import bisect_left

MAX_N = 1500 * 1501 // 2

triangle = [0] * 1500
for i in range(1, 1500):
    triangle[i] = (i*(i+1))//2

dp = [0] * MAX_N

def isTriangle(n):
    idx = bisect_left(triangle, n)
    return triangle[idx] == n

def compute():
    dp[1] = 1
    for t in triangle[1:]:
        if t < len(dp):
            dp[t] = t*t

    curr = 2
    row = 2
    while (curr < MAX_N):
        for i in range(curr, curr + row - 1):
            dp[i] = i*i + dp[i - row + 1]
        curr += row
        row += 1
    # for i, e in enumerate(dp[:14]):
    #     print(f"{i}: {e}", end=" ")


if __name__ == "__main__":
    t = int(input())
    compute()


    for _ in range(t):
        n = int(input())
        row = bisect_left(triangle, n)
        acc = 0
        curr = n
        delta = row

        for i in range(n - triangle[row - 1]):
            # print(curr, acc, delta)
            acc += dp[curr]
            curr -= delta
            delta -= 1
        print(acc)
