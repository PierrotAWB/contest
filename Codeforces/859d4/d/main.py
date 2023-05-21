#
#  author: awb29
#  created: Sat May 20 16:10:51 EDT 2023
#


if __name__ == "__main__":
    t = int(input())

    for _ in range(t):
        n, q = list(map(int, input().split(' ')))
        a = list(map(lambda s: int(s) % 2, input().split(' ')))
        pref = [0] * (n + 1)
        for i in range(1, n+1):
            pref[i] = (pref[i - 1] + a[i - 1]) % 2
        for _ in range(q):
            l, r, k = list(map(int, input().split(' ')))
            if (pref[n] + (r - l + 1) * k - (pref[r] - pref[l - 1])) % 2 == 1:
                print("YES")
            else:
                print("NO")

