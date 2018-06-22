# brute force, try all combinations 
# insertions for brackets performed by hand
# runs in ~35 seconds on 3.1 GHz i5

import itertools, time

it = time.time()

a = list(itertools.combinations([i for i in range(10)], 4))
b = list(itertools.product(["+", "-", "*", "/"], repeat=3))
global t
t = set([])


def createExpression(p, q):
    s = str(float(p[3]))
    for i in range(2, -1, -1):
        s = str(float(p[i])) + q[i] + s
    return s

def tryExpression(s):
    try:
        r = eval(s)
        if r % 1 == 0:
            t.add(r)
    except ZeroDivisionError:
        return

def maxReachable(d):
    c = list(itertools.permutations(d, 4))
    for p in c: 
        for q in b:
            s = createExpression(p, q)
            # no brackets
            tryExpression(s)

            # one set of brackets
                # enclosing two operands
            tryExpression("(" + s[:7] + ")" + s[7:])
            tryExpression(s[:4] + "(" + s[4:11] + ")" + s[11:])
            tryExpression(s[:8] + "(" + s[8:] + ")")

                # enclosing three operands
            tryExpression("(" + s[:11] + ")" + s[11:])
            tryExpression(s[:4] + "(" + s[4:] + ")")

            # two sets of brackets 
                # outside pair enclosing operands 1-3
                    # inside pair enclosing 1 and 2
            tryExpression("((" + s[:7] + ")" + s[7:11] + ")" + s[11:])
                # inside pair enclosing 2 and 3
            tryExpression("(" + s[:4] + "(" + s[4:11] + "))" + s[11:])
    
                # outside pair enclosing operands 2-4
                    # inside pair enclosing 2 and 3
            tryExpression(s[:4] + "((" + s[4:11] + ")" + s[11:] + ")")
                # inside pair enclosing 3 and 4
            tryExpression(s[:4] + "(" + s[4:8] + "(" + s[8:] + "))")
                    # enclosing operands 1 and 2, and 3 and 4
            tryExpression("(" + s[:7] + ")" + s[7:8] + "(" + s[8:] + ")")
    
    i = 0
    while True:
        if i not in t:
            break
        i += 1
    return i - 1

print maxReachable([1, 2, 3, 4])


maxTarget = 0
l = []
for i in range(len(a)):
    currentMax = maxReachable(a[i])
    t.clear()
    if currentMax > maxTarget: 
        maxTarget = currentMax
        l = a[i]
        
l = sorted(l)
s = ""
for i in l:
    s += str(i)
print s, "Executed in:", time.time() - it, "seconds."























        
