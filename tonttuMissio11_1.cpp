#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;



class Monkey {
    public:
        char oper;
        int num;
        int test;
        int tmonk;
        int fmonk;
        vector<int> items;

        void monkeyItem(int item) {
            items.push_back(item);
        }

        int monkeyOperation(int old) {
            if (num == 0) {
                return old * old;
            } else if (oper == '*') {
                return old * num;
            } else {
                return old + num;
            }
        }

        int monkeyTest(int old) {
            return monkeyOperation(old) % test; 
        }

        int monkeyReturn(int old) {
            // true
            if (!monkeyOperation(old)) {
                return tmonk;
            } else {
                return fmonk;
            }
        }
};

int main() {

    string stack[9];
    
    string monkeys;

    ifstream readMonkeys("input11.txt");

    int lineNumber = 0;

    int currentMonkey;

    Monkey monke[7];
 
    while (getline (readMonkeys, monkeys)) {
        lineNumber += 1;
        if (monkeys[0] == 'M') {
            currentMonkey = monkeys[7] -48;
        }
        if (monkeys[2] == 'S') {
            for (int i = 18; i < monkeys.length(); i += 4) {
                monke[currentMonkey].monkeyItem(stoi(monkeys.substr(i)));
            }
        }
        if (monkeys[2] = 'O') {
            monke[currentMonkey].oper = monkeys[24];
            if (monkeys.substr(25) == "old") {
                monke[currentMonkey].num = 0;
            } else {
                monke[currentMonkey].num = stoi(monkeys.substr(25));
            }
        }
        if (monkeys[2] = 'T') {
            monke[currentMonkey].test = stoi(monkeys.substr(25));
        }
        if (monkeys[7] = 't') {

        }
        if (monkeys[7] = 'f') {

        }
        
        

    }

    return 0;
}

