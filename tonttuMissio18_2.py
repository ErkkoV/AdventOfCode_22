import numpy

tonttuFile1 = open("input18.txt", "r")
tonttuFile2 = open("input18.txt", "r")

maxX = 0
maxY = 0
maxZ = 0

freetotal = 0
finalFree = 0
pocketstotal = 0

for line in tonttuFile1:
    newline = line.split(",")
    x = int(newline[0])
    y = int(newline[1])
    z = int(newline[2])

    if x + 1 > maxX:
        maxX = x + 1
    if y + 1 > maxY:
        maxY = y + 1
    if z + 1 > maxZ:
        maxZ = z + 1

grid = numpy.array([[[0] * maxZ] * maxY] * maxX)


for line in tonttuFile2:
    newline = line.split(",")
    x = int(newline[0])
    y = int(newline[1])
    z = int(newline[2])

    grid[x][y][z] = 1

notFree = grid.copy()
useGrid = grid.copy()

for x in range(maxX):
    for y in range(maxY):
        for z in range(maxZ):
            if grid[x][y][z] == 1:
                free = 6
                # z- check
                if z > 0 and grid[x][y][z - 1] != 0:
                    free -= 1
                # z+ check
                if z < 19 and grid[x][y][z + 1] != 0:
                    free -= 1
                # y- check
                if y > 0 and grid[x][y - 1][z] != 0:
                    free -= 1
                # y+ check
                if y < 19 and grid[x][y + 1][z] != 0:
                    free -= 1
                # x- check
                if x > 0 and grid[x - 1][y][z] != 0:
                    free -= 1
                # x+ check
                if x < 19 and grid[x + 1][y][z] != 0:
                    free -= 1

                freetotal += free

                useGrid[x][y][z] = -free

for a in range(maxX):
    for b in range(maxY):
        for c in range(maxZ):
            if useGrid[a][b][c] == 0:
                # for every grid with 0
                newGrid = useGrid.copy()
                loop = 1
                notBlocked = True
                newGrid[a][b][c] = 1
                while loop < 20:
                    for x in range(maxX):
                        for y in range(maxY):
                            for z in range(maxZ):
                                if newGrid[x][y][z] == loop:
                                    # z- check
                                    if z > 0 and newGrid[x][y][z - 1] == 0:
                                        newGrid[x][y][z - 1] = loop + 1
                                    # z+ check
                                    if z < maxZ - 1 and newGrid[x][y][z + 1] == 0:
                                        newGrid[x][y][z + 1] = loop + 1
                                    # y- check
                                    if y > 0 and newGrid[x][y - 1][z] == 0:
                                        newGrid[x][y - 1][z] = loop + 1
                                    # y+ check
                                    if y < maxY - 1 and newGrid[x][y + 1][z] == 0:
                                        newGrid[x][y + 1][z] = loop + 1
                                    # x- check
                                    if x > 0 and newGrid[x - 1][y][z] == 0:
                                        newGrid[x - 1][y][z] = loop + 1
                                    # x+ check
                                    if x < maxX - 1 and newGrid[x + 1][y][z] == 0:
                                        newGrid[x + 1][y][z] = loop + 1

                                    if (
                                        x == 19
                                        or x == 0
                                        or y == 19
                                        or y == 0
                                        or z == 19
                                        or z == 0
                                    ):
                                        notBlocked = False
                                        loop += 20
                    loop += 1

                if notBlocked:
                    notFree[a][b][c] = 1
                    print("not free")


for x in range(maxX):
    for y in range(maxY):
        for z in range(maxZ):
            if notFree[x][y][z] == 1:
                free = 6
                # z- check
                if z > 0 and notFree[x][y][z - 1] != 0:
                    free -= 1
                # z+ check
                if z < 19 and notFree[x][y][z + 1] != 0:
                    free -= 1
                # y- check
                if y > 0 and notFree[x][y - 1][z] != 0:
                    free -= 1
                # y+ check
                if y < 19 and notFree[x][y + 1][z] != 0:
                    free -= 1
                # x- check
                if x > 0 and notFree[x - 1][y][z] != 0:
                    free -= 1
                # x+ check
                if x < 19 and notFree[x + 1][y][z] != 0:
                    free -= 1

                finalFree += free


print(finalFree)
