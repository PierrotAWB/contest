def straight(nums):
    if nums == [14, 2, 3, 4, 5]:
        return 5
    if not sum([abs(nums[i] - nums[0] - i) for i in range(5)]):
        return nums[-1]
    return False

def flush(suits):
    return len(set(suits)) == 1

# returns (count, value) for each present value, sorted by count then by value
def groups(nums):
    groups = []
    for n in set(nums): groups.append((nums.count(n), n))
    groups.sort()
    groups.reverse()
    return groups

def hand(cards):
    cards.sort()
    nums = [c[0] for c in cards]
    suits = [c[1] for c in cards]
    s, f = straight(nums), flush(suits)

    # (2, 2, 1) == two_pair, (3, 1, 1) == three_of_a_kind
    of_a_kind  = [count for count,value in groups(nums)]
    # order matches of_a_kind, ties broken in descending value
    signature = [value for count,value in groups(nums)]

    # return values are ordered lexicographically by hand then by values
    # straights handled separately to correctly order A2345 < 23456
    if  s and f: return 8, s
    if of_a_kind == [4, 1]: return 7, signature
    if of_a_kind == [3, 2]: return 6, signature
    if f: return 5, signature
    if s: return 4, s
    if of_a_kind == [3, 1, 1]: return 3, signature
    if of_a_kind == [2, 2, 1]: return 2, signature
    if of_a_kind == [2, 1, 1, 1]: return 1, signature
    return 0, signature

#value parser
vals = {'A':14,'T':10,'J':11,'Q':12,'K':13}
for i in range(2, 10): vals[str(i)] = i

count = 0
for h in [line.split() for line in open("poker.txt", 'r').xreadlines()]:
    p1 = [(vals[a], b) for a, b in h[:5]]
    p2 = [(vals[a], b) for a, b in h[5:]]
    if hand(p1) > hand(p2):
        count += 1
print count