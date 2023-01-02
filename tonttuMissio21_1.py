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


def findNums(monk):
    monkey = monkeys[monk]

    result = 0

    if len(monkey) == 1:
        result = monkey[0]
    else:
        operator = monkey[1]

        num1 = findNums(monkey[0])
        num2 = findNums(monkey[2])

        if operator == "+":
            result = num1 + num2
        elif operator == "-":
            result = num1 - num2
        elif operator == "/":
            result = num1 / num2
        elif operator == "*":
            result = num1 * num2

    return result


result = findNums("root")

print(result)
