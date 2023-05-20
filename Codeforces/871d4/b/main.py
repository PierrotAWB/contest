#
#  author: awb29
#  created: Sat May 20 11:11:38 EDT 2023
#

def solve():
    n = int(input())
    arr = input().split(' ')
    best = -1
    curr = 0
    for i in range(len(arr)):
        if arr[i] == '0':
            curr += 1
        else:
            curr = 0
        best = max(best, curr)
    print(best)

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
