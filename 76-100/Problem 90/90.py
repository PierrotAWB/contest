'''
My old solution is included at the bottom of this program. 
I assumed that digits could be reused. This was a huge headache.
I did learn that it's unbelievably important to read the 
question properly, though! That's why I included it.
The current solution is brute-force, but completes in under 1 second.
'''
import itertools, time
t = time.time()

# an arrangement isSquare if all 
# of 01, 04, 09, 16, 25,..., 81 can be displayed 
targets = ["01", "04", "09", "16", "25", "36", "49", "64", "81"]
def isSquare(M, N):
	l = set([])

	for i in M: 
		for j in N:
			l.add(str(i) + str(j))
			l.add(str(j) + str(i))
			if i == 6: 
				l.add("9" + str(j))
				l.add(str(j) + "9")
			elif i == 9: 
				l.add("6" + str(j))
				l.add(str(j) + "6")
			if j == 6: 
				l.add(str(i) + "9")
				l.add("9" + str(i))
			elif j == 9: 
				l.add(str(i) + "6") 
				l.add("6" + str(i))
	for target in targets: 
		if target not in l:
			return False

	return True

arrangements = []

A = list(itertools.combinations([0, 1, 2, 3, 4, 5, 6, 7, 8, 9], 6))
# print A
for i in range(len(A)):
	for j in range(i, len(A)):
		A[i] = sorted(A[i]); A[j] = sorted(A[j])
		if isSquare(A[i], A[j]):
			if [A[i], A[j]] not in arrangements:
				arrangements.append([A[i], A[j]])

print arrangements, len(arrangements), time.time() - t








# INCORRECT SOLUTION


''' 
Firstly, we will ignore 9 initially. We use only 6, and then
account for this fact at the end. Since they are interchangeable 
digits, all we have to do is account for 2^n arrangements 
every time we have n 6's. This is because we can "toggle" each one
of those 6's without consequence (i.e., toggling would preserve
the property of forming all "two digit" squares).

This solution is largely motivated by a working I did by hand.
I started by putting 0 into the "first" cube. 

At first I thought this would mean that 1, 4, and 6 would necessarily be in
the other hand like so: 

[0, A, B, C, D, E], [1, 4, 6, F, G, H].                	(1)

However, I realized that 1, 4, and 6 can be placed in the "first" cube 
as well, provided that at least one of F, G, or H is 0, like so:

[0, 1, 4, 6, I, J], [0, K, L, M, N, O].                	(2)

However, you'll realize that (2) is a subcase of (1). To see this, 
take A = 1, B = 4, C = 6, F = 0, and assign the rest a new letter.
Thus, we can always assume that successful arrangements will be in the
same form as that of (1).

With 8 variables in (1), our search space for candidate arrangements
would have 9^8 ~ 43M elements (we're discounting the digit 9, remember).

This was a bit much for me, considering that I hadn't even done much dirty 
work yet. So I looked for other distinguishing digits. It turns out that 
25 is a key player here. In fact, it gives rise to exactly two subcases of (1):

(We'll reuse the letters, but for the record they are unrelated to those of 
previous arrangements used as examples)

[0, 2, A, B, C, D], [1, 4, 5, 6, E, F].               	(3)
and
[0, 5, A, B, C, D], [1, 2, 4, 6, E, F].               	(4)

Now, unfortunately, there is, once again, some overlap between these two. 
Not to worry, though, since as we do more work, we'll see that it's
viable to produce these overlaps and check them against a set of 
already successful arrangements. This way, we won't add to a the set 
of successful arrangements what is already there. Of course, in terms
of implementation detail, this is not doable as described because
lists are not hashable objects. A workaround, though, is to sort 
each cube's digits and do a simple list comparison.

Anyway, we aren't done. We still haven't used the fact that 8 must be in a set
that's opposite a 1. This either means that the "second" cube has at least one
1 and the 8 is in the "first cube", or that the first cube has at least one 1
and the 8 is in the "second cube". This produces four cases:

From (3):
[0, 2, 8, A, B, C], [1, 4, 5, 6, D, E].               	(5)
[0, 1, 2, A, B, C], [1, 4, 5, 6, 8, D]. 				(6)		  

From (4):
[0, 5, 8, A, B, C], [1, 2, 4, 6, D, E]. 				(7)
[0, 1, 5, A, B, C], [1, 2, 4, 6, 8, D]. 				(8)

We are now down to 9^5 + 9^4 + 9^5 + 9^4 = 131220 cases. Quite the improvement!

The last stage of this that I did by hand was adding a 3. Following the previous
logic, since all of (5) to (8) have a 6 in the "second cube", it would 
be possible to simply put a 3 in the "first cube". On the other hand, 
it could be the case that the "first hand" contains one or more 6's (just
let A, B, or C take this role), and the three can be put in the 
"second hand". This produces eight cases, whose combined search space now
contains 16200 elements. 

How good is this optimization? If all we did was try every possible permutation
(yes, permutation), without ignoring 9's, or doing any sort of reasoning,
we would have a search space of 9^12 = 2.8*10^11 elements! If we could
test 10^8 permutations per second (a very generous assumption, since
each check is potentially dozens of operations), this would take almost five 
minutes! (In reality, this may take dozens of times longer!).

Whereas, at the same speed, it takes about a tenth of a millisecond to 
check all 16200 of the "reasoned-out" cases. 

Obviously, these estimates are very rough, but the optimization is clearly
very powerful.

Note, that I could have further optimized with 6's in the "first cube", since, 
the 4's are all in the "second cube". This would produce fewer than 16 cases,
though I can't be asked to actually name them all (some 6's are in the "first
cube", which would allow a 49 to be formed).
'''


# candidateArrangements = []

# # t is number of empty digits in cube 2
# # M is the list of known digits in the first cube
# # N '' second ''

# A = list(itertools.combinations([0, 1, 2, 3, 4, 5, 6, 7, 8], 2))

# def checkCase(M, N, t):
# 	# first cube will always have two empty digits
# 	B = []
# 	# add the digits given by A into M, rinse, and repeat
# 	for x in A: 
# 		M.append(x[0]); M.append(x[1])
# 		B.append(M[:])
# 		M.pop(); M.pop()

# 	# second cube has t empty digits
# 	C = list(itertools.combinations([0, 1, 2, 3, 4, 5, 6, 7, 8], t))

# 	D = []
# 	if t == 0:
# 		D.append(N[:])
# 	elif t == 1:
# 		for x in C:
# 			N.append(x[0])
# 			D.append(N[:])
# 			N.pop()
# 	else: 
# 		for x in C:
# 			N.append(x[0]); N.append(x[1])
# 			D.append(N[:])
# 			N.pop(); N.pop()

# 	for i in B: 
# 		for j in D:
# 			if isSquare(i, j):
# 				if [sorted(i), sorted(j)] not in candidateArrangements and [sorted(j), sorted(i)] not in candidateArrangements:
# 						candidateArrangements.append([sorted(i), sorted(j)])


# if __name__ == "__main__":
# 	# check the cases with two empty digits in cube 2:
# 	checkCase([0, 2, 3, 8], [1, 4, 5, 6], 2)
# 	checkCase([0, 3, 5, 8], [1, 2, 4, 6], 2)

# 	# check the cases with one empty digits in cube 2:
# 	checkCase([0, 2, 6, 8], [1, 3, 4, 5, 6], 1)
# 	checkCase([0, 1, 2, 3], [1, 4, 5, 6, 8], 1)
# 	checkCase([0, 5, 6, 8], [1, 2, 3, 4, 6], 1)
# 	checkCase([0, 1, 3, 5], [1, 2, 4, 6, 8], 1)

# 	# check the cases wherein all cube 2 digits are known
# 	checkCase([0, 1, 2, 6], [1, 3, 4, 5, 6, 8], 0)
# 	checkCase([0, 1, 5, 6], [1, 2, 3, 4, 6, 8], 0)

# 	for i in candidateArrangements:
# 		print i

# 	arrCount = 0

# 	for i in candidateArrangements:
# 		n_six = i[0].count(6) + i[1].count(6)
# 		arrCount += 2 ** n_six

# 	print arrCount









