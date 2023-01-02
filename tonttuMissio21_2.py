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


low = 0
high = 1e30

while cont:
    test = (low + high) // 2

    res = findNums("root", test)

    if res[0] == res[1]:
        cont = False
        finalRes = test
        break
    elif res[0] - res[1] > 0:
        low = test
    else:
        high = test


print(finalRes)
