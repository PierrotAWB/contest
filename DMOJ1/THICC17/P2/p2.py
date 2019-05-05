N, A0, B, M = map(int, input().split(' '))
accum = prev = A0; squareAccum = A0 ** 2
for i in range(1, N):
	Ai = (prev * B) % M
	prev = Ai
	accum = (accum + Ai % 1000000007) % 1000000007
	squareAccum = (squareAccum + (Ai % 1000000007) ** 2) % 1000000007
# print (accum, squareAccum)
print ((accum * accum - squareAccum) % 1000000007)
