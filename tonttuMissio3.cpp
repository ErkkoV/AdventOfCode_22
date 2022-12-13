#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main() {

    string container;

    ifstream readContainers("containerlist.txt");

    string charList = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int prioritySum;

    while (getline (readContainers, container)) {
        string container1 = container.substr(0, (container.length() + 1)/2);
        string container2 = container.substr((container.length() + 1)/2);

        char item;
        int itemPriority;

        for (char item1 : container1) {
            for (char item2 : container2) {
                if (item1 == item2) {
                    item = item1;
                }
            }
        }

  
        for (int i = 0; i < 53; i++) {
            if (charList[i] == item) {
                itemPriority = i + 1;
            }   
        }

        prioritySum += itemPriority;

    }

    cout << prioritySum;

    return 0;
}