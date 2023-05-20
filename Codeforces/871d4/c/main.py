#
#  author: awb29
#  created: Sat May 20 11:13:54 EDT 2023
#

INF = 4_000_001

def solve():
    n = int(input())

    bests = {'00':INF, '01':INF, '10':INF, '11':INF}

    for _ in range(n):
        m, s = input().split(' ')
        m = int(m)
        bests[s] = min(bests[s], m)

    if bests['11'] == INF and (bests['01'] == INF or bests['10'] == INF):
        print(-1)
    else:
        print(min(bests['11'], bests['01'] + bests['10']))


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
