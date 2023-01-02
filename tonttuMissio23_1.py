import numpy

tonttuFile = open("input23.txt", "r")

grid = numpy.array([[0] * 1000] * 1000)

linenum = 0
elfs = 0

for line in tonttuFile:
    for i in range(len(line)):
        if line[i] == "#":
            grid[linenum + 500][i + 500] = 1
            elfs += 1
    linenum += 1


def north(x, y):
    if grid[x - 1][y] == 0 and grid[x - 1][y + 1] == 0 and grid[x - 1][y - 1] == 0:
        return [x, y, x - 1, y]
    else:
        return False


def south(x, y):
    if grid[x + 1][y] == 0 and grid[x + 1][y + 1] == 0 and grid[x + 1][y - 1] == 0:
        return [x, y, x + 1, y]
    else:
        return False


def west(x, y):
    if grid[x][y - 1] == 0 and grid[x + 1][y - 1] == 0 and grid[x - 1][y - 1] == 0:
        return [x, y, x, y - 1]
    else:
        return False


def east(x, y):
    if grid[x][y + 1] == 0 and grid[x + 1][y + 1] == 0 and grid[x - 1][y + 1] == 0:
        return [x, y, x, y + 1]
    else:
        return False


checkList = [north, south, west, east]


def move(x, y):
    if (
        grid[x - 1][y - 1] == 0
        and grid[x - 1][y] == 0
        and grid[x - 1][y + 1] == 0
        and grid[x][y + 1] == 0
        and grid[x + 1][y + 1] == 0
        and grid[x + 1][y] == 0
        and grid[x + 1][y - 1] == 0
        and grid[x][y - 1] == 0
    ):
        return [x, y, x, y]

    for i in range(4):
        if checkList[i](x, y):
            return checkList[i](x, y)
    return [x, y, x, y]


for i in range(10):
    proposedMoves = []

    for x in range(1000):
        for y in range(1000):
            if grid[x][y] == 1:
                proposedMoves.append(move(x, y))

    for a in range(len(proposedMoves)):
        for b in range(len(proposedMoves)):
            if (
                not (
                    proposedMoves[a][0] == proposedMoves[b][0]
                    and proposedMoves[a][1] == proposedMoves[b][1]
                )
                and proposedMoves[a][2] == proposedMoves[b][2]
                and proposedMoves[a][3] == proposedMoves[b][3]
            ):
                proposedMoves[a][2] = proposedMoves[a][0]
                proposedMoves[b][2] = proposedMoves[b][0]
                proposedMoves[a][3] = proposedMoves[a][1]
                proposedMoves[b][3] = proposedMoves[b][1]

    newGrid = numpy.array([[0] * 1000] * 1000)

    for i in range(len(proposedMoves)):
        newGrid[proposedMoves[i][2]][proposedMoves[i][3]] = 1

    grid = newGrid

    checkList.append(checkList.pop(0))

high = 1000
low = 0
left = 1000
right = 0

for x in range(1000):
    for y in range(1000):
        if grid[x][y] == 1 and x < high:
            high = x
        if grid[x][y] == 1 and x > low:
            low = x
        if grid[x][y] == 1 and y < left:
            left = y
        if grid[x][y] == 1 and y > right:
            right = y

totalArea = (low - high + 1) * (right - left + 1)

print(low, high, left, right)


print(totalArea - elfs)
