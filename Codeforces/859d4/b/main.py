#
#  author: awb29
#  created: Sat May 20 16:01:05 EDT 2023
#

def solve():
    n = int(input())
    a = list(map(int, input().split(' ')))
    evens = []
    odds = []
    for x in a:
        if x % 2 == 0:
            evens.append(x)
        else:
            odds.append(x)
    if sum(evens) > sum(odds):
        print("yes")
    else:
        print("no")

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
