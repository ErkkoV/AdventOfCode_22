#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;



class Monkey {
    public:
        vector<int> items;

        void monkeyItem(int item) {
            items.push_back(item);
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
            vector<int> itemlist;
            for (int i = 18; i < monkeys.length(); i += 4) {
                itemlist.push_back(stoi(monkeys.substr(i)));
            }
            monke[currentMonkey].items = itemlist;
        }
        
        

    }

    return 0;
}

