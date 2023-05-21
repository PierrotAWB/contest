#
#  author: awb29
#  created: Sat May 20 15:57:30 EDT 2023
#

def solve():
    a, b, c = map(int, input().split(' '))
    if a + b == c:
        print("+")
    else:
        print("-")

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
