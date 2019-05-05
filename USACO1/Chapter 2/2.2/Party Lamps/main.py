'''
ID: andreww7
TASK: lamps
LANG: PYTHON2
'''
def genState(n): 
	if n == 1: 
		return ["0", "1"]

	L = genState(n - 1)
	a = []
	for i in L: 
		a.append(i + "0")
		a.append(i + "1")
	return a

def processState(state, length):
	# process the state and yield the final result
	l = [1]*length
	if state[0] == "1": 
		for i in range(1, length): 
			if l[i] == 1: 
				l[i] = 0
			else: 
				l[i] = 1
	if state[1] == "1": 
		for i in range(1, length, 2): 
			if l[i] == 1: 
				l[i] = 0
			else: 
				l[i] = 1
	if state[2] == "1": 
		for i in range(2, length, 2):
			if l[i] == 1: 
				l[i] = 0
			else: 
				l[i] = 1
	if state[3] == "1": 
		for i in range(1, length, 3): 
			if l[i] == 1: 
				l[i] = 0
			else: 
				l[i] = 1
	return l

def guard(stateSpace, C): 
	return [i for i in stateSpace if i.count("1") <= C]

def isPossibleFinalState(k): 
	for i in on: 
		if k[i] == 0:
			return False 

	for i in off: 
		if k[i] == 1:
			return False

	return True


if __name__ == "__main__":
	# Handle input
	with open("lamps.in", "r") as input: 
		N = int(input.readline())
		C = int(input.readline())
		on = list(map(int, input.readline().split()))
		on.pop()
		off = list(map(int, input.readline().split()))
		off.pop()
		input.close()

	finalState = [1]*(N + 1) # 1-index
	for i in off: 
		finalState[i] = 0

	# state space contains all possible on-off states of the switches
	# if C <= 4, guard against too many switches
	stateSpace = genState(4)
	if C <= 4: 
		stateSpace = guard(stateSpace, C)

	possibleFinalState = []

	for i in stateSpace: 
		k = processState(i, N + 1)
		if isPossibleFinalState(k): 
			del k[0]
			possibleFinalState.append(''.join(list(map(str, k))))

	possibleFinalState = list(set(possibleFinalState))
	possibleFinalState = sorted(possibleFinalState)

	with open("lamps.out", 'w') as output:
		if len(possibleFinalState) > 0: 
			for i in possibleFinalState:
				output.write(str(i) + "\n")
		else: 
			output.write("IMPOSSIBLE\n")

















