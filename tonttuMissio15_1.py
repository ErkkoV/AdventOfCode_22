import numpy

totalList = numpy.array([0] * 10000000)

totalCover = 0

tonttuFile = open("input15.txt", "r")

sensors = []

coverLine = []

set()

for line in tonttuFile:
    newline = line.split("=")
    locationX = int(newline[1].split(",")[0])
    locationY = int(newline[2].split(":")[0])
    beaconX = int(newline[3].split(",")[0])
    beaconY = int(newline[4])

    covers = abs(locationX - beaconX) + abs(locationY - beaconY)

    sensors.append({"x": locationX, "y": locationY, "cover": covers})


def coverCheck(origin, value):
    rangevalue = int(value)

    left = origin - rangevalue
    right = origin + rangevalue

    coverLine.append([left, right])


for i in range(len(sensors)):
    coverrange = 0

    if sensors[i]["y"] < 2000000:
        if sensors[i]["y"] + sensors[i]["cover"] >= 2000000:
            coverrange = abs(2000000 - (sensors[i]["y"] + sensors[i]["cover"]))
            coverCheck(sensors[i]["x"], coverrange)
    else:
        if sensors[i]["y"] - sensors[i]["cover"] <= 2000000:
            coverrange = abs(2000000 - (sensors[i]["y"] - sensors[i]["cover"]))
            coverCheck(sensors[i]["x"], coverrange)

    totalCover += coverrange


for a in range(len(coverLine)):

    arr = numpy.arange(coverLine[a][0] + 13015, coverLine[a][1] + 13015)

    numpy.put(totalList, [arr], [1])


result = numpy.count_nonzero(totalList > 0)


print(result)
