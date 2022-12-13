#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main() {

    string cleaners;

    ifstream readCleaning("cleaninglist.txt");

    int overlap;

    while (getline (readCleaning, cleaners)) {
        string areaA = cleaners.substr(0, cleaners.find(',')); 
        string areaB = cleaners.substr(cleaners.find(',') + 1);

        int areaA1 = stoi(areaA.substr(0, areaA.find('-')));
        int areaA2 = stoi(areaA.substr(areaA.find('-') +1));

        int areaB1 = stoi(areaB.substr(0, areaB.find('-')));
        int areaB2 = stoi(areaB.substr(areaB.find('-') +1));

        if (areaA1 >= areaB1 && areaA2 <= areaB2) {
            overlap += 1;
        } else if (areaB1 >= areaA1 && areaB2 <= areaA2) {
            overlap += 1;
        }
    }

    cout << overlap;

    return 0;
}