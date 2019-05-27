k = int(input()); s = ""; vowelly = False

for i in range(5, int(k**0.5 + 1)):
	if k % i == 0:
		vowelly = True
		l = [['z' for l in range(k/i)] for j in range(i)]
		m = {}
		m['a'] = [range(i), range(k/i)]
		m['e'] = [range(i), range(1, k/i) + range(1)]
		m['i'] = [range(i), range(2, k/i) + range(2)]
		m['o'] = [range(i), range(3, k/i) + range(3)]
		m['u'] = [range(i), range(4, k/i) + range(4)]
		for letter in ['a', 'e', 'i', 'o', 'u']:
			while len(m[letter][0]) > 0 or len(m[letter][1]) > 0:
				# all rows satisfied
				if len(m[letter][0]) == 0:
					for col in m[letter][1]:
						for j in range(i):
							if l[j][col] == 'z':
								l[j][col] = letter
								m[letter][1] = m[letter][1][1:]
								break

				elif l[m[letter][0][0]][m[letter][1][0]] == 'z':
					l[m[letter][0][0]][m[letter][1][0]] = letter
					m[letter][0] = m[letter][0][1:]
					m[letter][1] = m[letter][1][1:]

if not vowelly: 
	print -1
else:
	for row in l:
		# print " ".join(row)
		s += "".join(row)
	print s