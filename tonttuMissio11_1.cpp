#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;



class Monkey {
    public:
        int count = 0;
        char oper;
        int num;
        int test;
        int tmonk;
        int fmonk;
        vector<int1024_t> items;

        void monkeyItem(int1024_t item) {
            items.push_back(item);
            // cout << items.size();
        }

        int monkeyOperation(int1024_t old) {
            if (num == 0) {
                return old * old;
            } else if (oper == '*') {
                return old * num;
            } else {
                return old + num;
            }
        }

        int monkeyOperation2(int1024_t old) {
            if (num == 0) {
                if (old * old < 0 || old * old > 10000) {
                    cout << "\n" << old << " * " << old; 
                    cout << "\n" << old * old;
                } 
                return (old * old) / 3;
            } else if (oper == '*') {
                if (old * num < 0 || old * num > 10000) {
                    cout << "\n" << old << " * " << num; 
                } 
                return (old * num) / 3;
            } else {
                if (old + num < 0 || old + num > 10000) {
                    cout << "\n" << old << " + " << num; 
                } 
                return (old + num) / 3;
            }
        }

        int monkeyTest(int1024_t old) {
            return monkeyOperation(old) % test; 
        }

        int monkeyReturn(int1024_t old) {
            if (!monkeyTest(old)) {
                return tmonk;
            } else {
                return fmonk;
            }
        }
};

int main() {

    string monkeys;

    ifstream readMonkeys("input11.txt");

    int lineNumber = 0;

    int currentMonkey;

    Monkey monke[8];
 
    while (getline (readMonkeys, monkeys)) {
        lineNumber += 1;
        if (monkeys[0] == 'M') {
            currentMonkey = monkeys[7] -48;
        }
        if (monkeys[2] == 'S') {
            
            for (int i = 18; i < monkeys.size(); i += 4) {
                int1024_t item = stoi(monkeys.substr(i));
                monke[currentMonkey].monkeyItem(item);
            }
        }
        if (monkeys[2] == 'O') {
            monke[currentMonkey].oper = monkeys[23];
            if (monkeys[25] == 'o') {
                monke[currentMonkey].num = 0;
            } else {
               monke[currentMonkey].num = stoi(monkeys.substr(25));
            }
        }
        if (monkeys[2] == 'T') {
            monke[currentMonkey].test = stoi(monkeys.substr(21));
        }
        if (monkeys[8] == 'r') {
            monke[currentMonkey].tmonk = monkeys[29] -48;
        }
        if (monkeys[7] == 'f') {
            monke[currentMonkey].fmonk = monkeys[30] -48;
        }
    }

    
    int round = 0;
    
    while (round < 20) {
        for (int i = 0; i < 8; i++) {
            for (int y = 0; y < monke[i].items.size(); y++) {
                int1024_t int targetmonkey = monke[i].monkeyReturn(monke[i].items[y]);
/*                 cout << "\n";
                cout << targetmonkey << ", " << monke[i].items[y]; */
                int1024_t int newItem = monke[i].monkeyOperation2(monke[i].items[y]);
                if (newItem > 10000 || newItem < 0) {
                    cout << "\n";
                    cout << newItem << ", " << monke[i].items[y];
                }

                monke[targetmonkey].items.push_back(newItem);
                monke[i].count +=1;
            }
            monke[i].items.clear();
        }

        round++;
    }

    for (int i = 0; i < 8; i++) {
        cout << "\n";
        cout << monke[i].count << ", ";
        cout << monke[i].oper << ", ";
        cout << monke[i].num << ", ";
        cout << monke[i].test << ", ";
        cout << monke[i].tmonk << ", ";
        cout << monke[i].fmonk << ", ";
        for (int y = 0; y < monke[i].items.size(); y++) {
            cout << monke[i].items[y] << ", ";
        }

    }



    

    return 0;
}

