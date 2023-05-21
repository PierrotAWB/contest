#
#  author: awb29
#  created: Sat May 20 16:05:02 EDT 2023
#

def solve():
    n = int(input())
    s = input()
    idx = {}

    possible = True

    for i in range(len(s)):
        if s[i] in idx:
            if i % 2 != idx[s[i]]:
                possible = False
                break
        else:
            idx[s[i]] = i % 2

    if possible:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
