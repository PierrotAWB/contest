"""
ID: andreww7
LANG: PYTHON3
TASK: kimbits
"""
def factorial(m):
    if m == 1 or m == 0:
        return 1
    return m * factorial(m - 1)

def choose(n, k):
    if k > n:
        return 0
    return int(factorial(n) / (factorial(n - k) * factorial(k)))    

def countLeft(ones, spaces):
    # Sum of C(spaces - 1, 0), C(space - 1, 1), ..., C(spaces - 1, ones)
    return sum(map(lambda x: choose(spaces - 1, x), range(ones + 1)))

def solve(N, L, I):
    ans = ""
    ones = L
    spaces = N
    x = I
    while len(ans) < N:
        l_count = countLeft(ones, spaces)
        if x > l_count:
        # Need to move right 
            ans += "1"
            ones -= 1
            x -= l_count 
        else:
        # Able to find xth in left subtree of current node
            ans += "0"
        spaces -= 1
    return ans
    
fin = open('kimbits.in', 'r') 
fout = open('kimbits.out', 'w')
N, L, I = map(int, fin.readline().split())
ans = solve(N, L, I)
fout.write(ans + '\n')
fout.close()
