n_puzzles = 50

puzzles = [[] for i in range(n_puzzles)]
SOLVED = False
UPPER_LEFT_SUM = 0

with open('p096_sudoku.txt', 'r') as sudoku:
    for i in range(n_puzzles):
        sudoku.readline() # Consume the "GRID N" line
        for j in range(9):
            puzzles[i].append(list(map(lambda x: int(str(x)), sudoku.readline().strip('\n'))))
sudoku.close()

def pprint(P):
    print("-"*29)
    for i in range(0, 9, 3):
        for j in range(i, i + 3):
            print (str(P[j][:3]) + "|" + str(P[j][3:6]) + "|" + str(P[j][6:]))
        print("-"*29)

# NAIVE

def getRange(x):
    if x in [0, 1, 2]:
        return [0, 1, 2]
    elif x in [3, 4, 5]:
        return [3, 4, 5]
    elif x in [6, 7, 8]:
        return [6, 7, 8]
    else:
        raise RuntimeException

def difference(s, l):
    return list(s.difference(set(l)))

def getCandidates(puzzle, i, j):
    fromRow = list(filter(lambda x: x != 0, set(puzzle[i])))
    fromCol = list(filter(lambda x: x != 0, map(lambda x: x[j], puzzle)))
    
    boxRows = getRange(i)
    boxCols = getRange(j)

    fromBox = []
    for r in boxRows:
        for c in boxCols:
            if puzzle[r][c] != 0:
                fromBox.append(puzzle[r][c])
    
    d = difference(set(list(range(1, 10))), fromRow + fromCol + fromBox + [0])
    return d

# Go through groups of three rows, groups of four rows, and fill
# in all that is certain


## MUST BE REWRITTEN TO RETURN A PAIR OF CHANGES; WHEN CALLING THIS IN SOLVE, 
## RETURNING MUST BE ACCOMPANIED BY UNDOING WHAT WAS DONE IN HERE -- Actually managed to avoid this by not calling in Solve; only before
def deduce(p):
    puzzle = p[:]
    for k in range(1, 10):
        # Check bands of three rows
        for l in range(0, 9, 3):
            unknown = []
            if k in puzzle[l]:
                a1 = puzzle[l].index(k)
            else:
                a1 = -1
                unknown.append(l)

            if k in puzzle[l+1]:
                a2 = puzzle[l+1].index(k)
            else:
                a2 = -1
                unknown.append(l+1)

            if k in puzzle[l+2]:
                a3 = puzzle[l+2].index(k)
            else:
                a3 = -1
                unknown.append(l+2)

            # two of three are known, add third one in
            knownHorIndices = list(filter(lambda x : x > 0, [a1, a2, a3]))
            if len(knownHorIndices) == 2 and len(set(knownHorIndices)) != 1 and len(unknown) == 1:
                arr = []
                for x in knownHorIndices:
                    arr.extend(getRange(x))
                poss = difference(set(list(range(9))), arr)
                accPoss = []
                for x in poss:
                    if puzzle[unknown[0]][x] != 0:
                        continue
                    if k in list(map(lambda r: r[x], puzzle)):
                        continue
                    accPoss.append(x)
                if len(accPoss) == 1:
                    puzzle[unknown[0]][accPoss[0]] = k

        # Check bands of three cols
        for l in range(0, 9, 3):
            unknown = []
            if k in list(map(lambda r: r[l], puzzle)):
                b1 = list(map(lambda r: r[l], puzzle)).index(k)
            else:
                b1 = -1
                unknown.append(l)

            if k in list(map(lambda r: r[l+1], puzzle)):
                b2 = list(map(lambda r: r[l+1], puzzle)).index(k)
            else:
                b2 = -1
                unknown.append(l+1)

            if k in list(map(lambda r: r[l+2], puzzle)):
                b3 = list(map(lambda r: r[l+2], puzzle)).index(k)
            else:
                b3 = -1
                unknown.append(l+2)

            knownVertIndices = list(filter(lambda y: y > 0, [b1, b2, b3]))
            if len(knownVertIndices) == 2 and len(set(knownVertIndices)) != 1 and len(unknown) == 1:
                arr = []
                for y in knownVertIndices:
                    arr.extend(getRange(y))
                poss = difference(set(list(range(9))), arr)
                accPoss = []
                for y in poss:
                    if puzzle[y][unknown[0]] != 0:
                        continue
                    if k in puzzle[y]:
                        continue
                    accPoss.append(y)
                if len(accPoss) == 1:
                    puzzle[accPoss[0]][unknown[0]] = k


    return puzzle 

def solve(puzzle, i, j):
    global SOLVED
    global UPPER_LEFT_SUM
    if SOLVED:
        return 

    if i == 9 and j == 0:
        print("Solved! Here's the puzzle:") 
        pprint(puzzle)
        SOLVED = True
        UPPER_LEFT_SUM += int("".join(map(str, puzzle[0][:3])))
        return

    if puzzle[i][j] != 0:
        if j == 8:
            solve(puzzle, i + 1, 0)
        else:
            solve(puzzle, i, j + 1)
        return

    candidates = getCandidates(puzzle, i, j)
    if len(candidates) == 0:
        return
    else:
        for k in range(len(candidates)):
            puzzle[i][j] = candidates[k]
            if j == 8:
                solve(puzzle, i + 1, 0)
            else:
                solve(puzzle, i, j + 1)
            puzzle[i][j] = 0


for i in range(n_puzzles):
    SOLVED = False
    print ("GRID " + str(i))
    pprint(puzzles[i])
    print("\n")
    while True:
        D = deduce(puzzles[i])
        if puzzles[i] != D:
            puzzles[i] = D
        else:
            break
    solve(puzzles[i], 0, 0)

print("Final answer: " + str(UPPER_LEFT_SUM))
