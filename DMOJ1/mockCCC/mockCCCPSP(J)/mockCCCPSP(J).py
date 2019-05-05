N = int(raw_input()) 
numList = map(int, raw_input().split())
numList = list(set(numList))
print len(numList)