import numpy

tonttuFile = open("input21.txt", "r")

monkeys = []

for line in tonttuFile:
    args = line.split(":")

    name = args[0]

    method = []

    if args[1][1].isdigit():
        method.append(int(args[1][1:]))
    else:
        methods = args[1].split(" ")
        method = [methods[1], methods[2], methods[3].split("\n")[0]]

    monkeys.append({name: method})


def findNums(monk):
    for i in range(len(monkeys)):
        for key in monkeys[i]:
            if key == monk:
                monkey = monkeys[i]

                result = 0

                if len(monkey[key]) == 1:
                    result = monkey[key][0]
                else:
                    operator = monkey[key][1]

                    num1 = findNums(monkey[key][0])
                    num2 = findNums(monkey[key][2])

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
