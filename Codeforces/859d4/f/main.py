#
#  author: awb29
#  created: Sun May 21 07:26:55 EDT 2023
#
dirs = {'DL': (1, -1), 'DR': (1, 1), 'UL': (-1, -1), 'UR': (-1, 1)}
srid = {v:k for k, v in dirs.items()}

def solve():
    n, m, i1, j1, i2, j2, d = input().split(' ')
    n = int(n)
    m = int(m)
    i1 = int(i1)
    j1 = int(j1)
    i2 = int(i2)
    j2 = int(j2)

    vis = set()
    q = [(i1, j1, d, 0)]
    req = -1
    while q:
        (a, b, di, bounces) = q.pop()
        a = int(a)
        b = int(b)
        bounces = int(bounces)

        # If target reachable
        k1 = (i2 - a) / dirs[di][0]
        k2 = (j2 - b) / dirs[di][1]

        if k1 >= 0 and k2 >= 0 and k1 == k2:
            req = bounces
            break
        if (a, b, di) in vis:
            break

        vis.add((a, b, di))

        if dirs[di][0] > 0:
            vertical_distance = n - a
        else:
            vertical_distance = a - 1

        if dirs[di][1] > 0:
            horizontal_distance = m - b
        else:
            horizontal_distance = b - 1

        k = min(vertical_distance, horizontal_distance)
        if k == vertical_distance and k == horizontal_distance:
            newd = srid[(-dirs[di][0], -dirs[di][1])]
        elif k == vertical_distance:
            newd = srid[(-dirs[di][0], dirs[di][1])]
        elif k == horizontal_distance:
            newd = srid[(dirs[di][0], -dirs[di][1])]

        # print("Bounced at", a + k*dirs[di][0], b + k*dirs[di][1], "changed dir to", newd)
        q.append((a + k*dirs[di][0], b + k*dirs[di][1], newd, bounces + 1))


    print(req)




if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve()
