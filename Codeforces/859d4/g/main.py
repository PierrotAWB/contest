#
#  author: awb29
#  created: Sun May 21 10:34:56 EDT 2023
#


def solve():
    n = int(input())
    c = list(map(int, input().split(' ')))
    c = sorted(c)

    if c[0] != 1:
        print("NO")
        return

    acc = 1
    for i in range(1, len(c)):
        if c[i] > acc:
            print("NO")
            return
        else:
            acc += c[i]
    print("YES")

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
