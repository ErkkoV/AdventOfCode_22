import numpy

tonttuFile = open("input21.txt", "r")

monkeys = {}

for line in tonttuFile:
    args = line.split(":")

    name = args[0]

    method = []

    if args[1][1].isdigit():
        monkeys[name] = [int(args[1][1:])]
    else:
        methods = args[1].split(" ")
        method = [methods[1], methods[2], methods[3].split("\n")[0]]
        monkeys[name] = method


def findNums(monk, arg):
    monkey = monkeys[monk]

    result = 0

    if len(monkey) == 1:
        if monk == "humn":
            result = arg
        else:
            result = monkey[0]
    else:
        operator = monkey[1]

        num1 = findNums(monkey[0], arg)
        num2 = findNums(monkey[2], arg)

        if operator == "+":
            result = num1 + num2
        elif operator == "-":
            result = num1 - num2
        elif operator == "/":
            result = num1 / num2
        elif operator == "*":
            result = num1 * num2

    if monk == "root":
        return [num1, num2]
    else:
        return result


cont = True
iter = 0
finalRes = False


def iterFind(it, resolution1, resolution2):
    print(resolution2[0] - resolution2[1])

    if resolution2[0] > resolution2[1] + 1e14:
        return it + 1e12
    elif resolution2[0] > resolution2[1] + 1e13:
        return it + 1e11
    elif resolution2[0] > resolution2[1] + 1e12:
        return it + 1e10
    elif resolution2[0] > resolution2[1] + 1e11:
        return it + 1e9
    elif resolution2[0] > resolution2[1] + 1e10:
        return it + 1e8
    elif resolution2[0] > resolution2[1] + 1e9:
        return it + 1e7
    elif resolution2[0] > resolution2[1] + 1e8:
        return it + 1e6
    elif resolution2[0] > resolution2[1] + 1e7:
        return it + 1e5
    elif resolution2[0] > resolution2[1] + 1e6:
        return it + 1e4
    elif resolution2[0] > resolution2[1] + 1e5:
        return it + 1e3
    elif resolution2[0] > resolution2[1]:
        return it + 1
    else:
        return it - 1


while cont:
    res1 = findNums("root", -iter)
    res2 = findNums("root", iter)

    if res1[0] == res1[1]:
        cont = False
        finalRes = -iter
        break
    if res2[0] == res2[1]:
        cont = False
        finalRes = iter
        break

    print(iter)

    iter = iterFind(iter, res1, res2)


print(finalRes)
