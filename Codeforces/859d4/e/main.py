#
#  author: awb29
#  created: Sat May 20 16:36:24 EDT 2023
#
from sys import stdout

def solve():
    n = int(input())
    a = list(map(int, input().split(' ')))
    pref = [0] * (n + 1)
    for i in range(1, n + 1):
        pref[i] = pref[i - 1] + a[i - 1]

    lo = 1
    hi = n

    while hi > lo:
        mid = (lo + hi) // 2

        print(f"? {mid - lo + 1} {' '.join(map(str, range(lo, mid + 1)))}")
        stdout.flush()
        actual_weight = int(input())

        if actual_weight == pref[mid] - pref[lo - 1]:
            # Stone occurs to the right
            lo = mid + 1
        else:
            hi = mid

    print(f"! {lo}")
    stdout.flush()

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
