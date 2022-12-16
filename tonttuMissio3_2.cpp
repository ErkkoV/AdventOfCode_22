#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main() {

    string container;

    ifstream readContainers("input3.txt");

    string charList = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int prioritySum;

    int lineNumber = 0;

    string line1 = "";
    string line2 = "";
    string line3 = "";

    while (getline (readContainers, container)) {
        char badge;

        int itemPriority;
        
        lineNumber += 1;

        if (line1 == "") {
            line1 = container;
        } else if (line2 == "") {
            line2 = container;
        } else {
            line3 = container;
        }


        if (lineNumber % 3 == 0) {
            for (char item1 : line1) {
                for (char item2: line2) {
                    for (char item3: line3) {
                        if (item1 == item2 && item1 == item3) {
                            badge = item1;
                        }
                    }
                }
            }
            line1 = "";
            line2 = "";
            line3 = "";

            for (int i = 0; i < 53; i++) {
                if (charList[i] == badge) {
                    itemPriority = i + 1;
                }   
            }
            prioritySum += itemPriority;
        }
    }

    cout << prioritySum;

    return 0;
}