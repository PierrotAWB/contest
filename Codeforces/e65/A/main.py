tt = int(input())
for i in range(tt):
    n = int(input())
    s = input()
    if n - s.find('8') < 11 or s.find('8') == -1:
        print("NO")
    else:
        print("YES")
