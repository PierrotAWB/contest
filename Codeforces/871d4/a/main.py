#
#   author: awb29
#   created: Sat May 20 11:09:59 EDT 2023
#

def solve():
    code = "codeforces"
    s = input()
    acc = 0
    for i in range(len(s)):
        if s[i] != code[i]:
            acc += 1
    print(acc)


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
