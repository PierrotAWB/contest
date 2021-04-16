from sys import stdout

a = [4, 8, 15, 16, 23, 42]

d = {}
for i in range(len(a)):
    for j in range(i + 1, len(a)):
        d[a[i]*a[j]] = [a[i], a[j]]

print("? 1 2")
stdout.flush()
a1a2 = int(input())

print("? 2 3")
stdout.flush()
a2a3 = int(input())

print("? 4 5")
stdout.flush()
a4a5 = int(input())

print("? 5 6")
stdout.flush()
a5a6 = int(input())

a2 = list((set(d[a1a2]) & set(d[a2a3])))[0]
a1 = a1a2 // a2
a3 = a2a3 // a2

a5 = list((set(d[a4a5]) & set(d[a5a6])))[0] 
a4 = a4a5 // a5
a6 = a5a6 // a5
print("! {} {} {} {} {} {}".format(a1, a2, a3, a4, a5, a6))
stdout.flush()
