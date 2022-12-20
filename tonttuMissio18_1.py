import numpy

tonttuFile1 = open("input18.txt", "r")
tonttuFile2 = open("input18.txt", "r")

maxX = 0
maxY = 0
maxZ = 0

freetotal = 0

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

print(freetotal)
