import collections, itertools, time
t = time.time()

perms = collections.defaultdict(list)
for cube in (b**3 for b in itertools.count()):
   cubes = perms[tuple(sorted(str(cube)))] # list of cubes with the same digits
   cubes.append(cube)
   if len(cubes) == 5:      
      break
#NOTE: I don't check that it has *exactly* five permutations
#      but it worked out for the problem
print cubes[0] # 127035954683 0.45 seconds
print time.time() - t
