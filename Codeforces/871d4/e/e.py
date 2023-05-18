# After setting recursionlimit, we have a segfault.

from sys import setrecursionlimit

dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

def solve():
    r = 1000; c = 1000
    arr = [[1000 for _ in range(1000)] for _ in range(1000)]
    # r, c = list(map(int, input().split(' ')))
    # arr = []

    # for _ in range(r):
    #     arr.append(list(map(int, input().split(' '))))

    seen = set()
    best = 0

    def dfs(v):
        if v in seen:
            return 0
        ans = arr[v[0]][v[1]]
        seen.add(v)
        for d in dirs:
            p, q = v[0] + d[0], v[1] + d[1]
            if 0 <= p < r and 0 <= q < c and arr[p][q] != 0:
                ans += dfs((p, q))

        return ans


    for i in range(r):
        for j in range(c):
            if not arr[i][j] == 0 and (i, j) not in seen:
                best = max(best, dfs((i, j)))

    print(best)


if __name__ == "__main__":
    # setrecursionlimit(1000000)
    t = int(input())
    # t = 1
    for _ in range(t):
        solve()
