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
        int iniover = 0;
        
        string areaA = cleaners.substr(0, cleaners.find(',')); 
        string areaB = cleaners.substr(cleaners.find(',') + 1);

        int areaA1 = stoi(areaA.substr(0, areaA.find('-')));
        int areaA2 = stoi(areaA.substr(areaA.find('-') +1));

        int areaB1 = stoi(areaB.substr(0, areaB.find('-')));
        int areaB2 = stoi(areaB.substr(areaB.find('-') +1));

        for (int i = areaA1; i < areaA2 + 1; i++) {
            if (i == areaB1 || i == areaB2 ) {
                iniover = 1;
                break;
            }
        }
        for (int i = areaB1; i < areaB2 + 1; i++) {
            if (i == areaA1 || i == areaA2 ) {
                iniover = 1;
                break;
            }
        }

        overlap += iniover;

    }

    cout << overlap;

    return 0;
}