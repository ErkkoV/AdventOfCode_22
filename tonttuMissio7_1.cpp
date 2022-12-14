#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main() {

    string folder1;
    string folder2;
    string folder3;

    ifstream readFolder1("folderinput.txt");
    ifstream readFolder2("folderinput.txt");
    ifstream readFolder3("folderinput.txt");

    int firstFolder = 0;
    string currentFolder = "root";
    int folderNumber = 0;
    vector<int> folderOrder;

    vector<int> folderSpaces;
    vector<string> folderNames;
    vector<vector<int>> folderUnder;
    vector<int> folderTotal;

    folderSpaces.push_back(0);
    folderNames.push_back("root");

    while (getline (readFolder1, folder1)) {
        // finds all folder names and assigns those into two vectors
        if (folder1[0] == 'd') {
            string folderName = folder1.substr(folder1.find(' ')+1);
            bool noNewName = false;
            for (int i = 0; i < folderNames.size(); i++) {
                if (folderNames[i] == folderName) {
                    noNewName = true;
                    cout << "\n replace stuff";
                } 
            }
            if (!noNewName) {
                folderSpaces.push_back(0);
                folderNames.push_back(folderName);
                // folderUnder.push_back({});
                folderTotal.push_back(0);
            }
        }
    }

    while (getline (readFolder2, folder2)) {
        // gets current folder name and updates folderspace size
        if (folder2.substr(0, 5) == "$ cd " && folder2.substr(0, 7) != "$ cd ..") {
            string folderName = folder2.substr(5);
            currentFolder = folderName;
        } else if (folder2[0] != '$' && folder2[0] != 'd') {
            int filesize = stoi(folder2.substr(0, folder2.find(' ')));
            for (int i = 0; i < folderNames.size(); i++) {
                if (folderNames[i] == currentFolder) {
                    folderSpaces[i] += filesize;
                }
            }
        }
    }

    currentFolder = "root";

    folderOrder.push_back(0);

    while (getline (readFolder3, folder3)) {
        // saves folders under each folder into vector
        if (folder3[0] == '$') {
            if (folder3.substr(0, 5) == "$ cd " && folder3.substr(0, 7) != "$ cd ..") {
                string folderName = folder3.substr(5);
                currentFolder = folderName;
                for (int i = 0; i < folderNames.size(); i++) {
                    if (folderNames[i] == currentFolder) {
                        folderOrder.push_back(i);
                    }
                }
                for (auto each: folderOrder) {
                    if (each <= folderOrder[folderOrder.size() -1]) {
                        folderUnder[each].push_back(folderOrder[folderOrder.size() -1]);
                    }
                }


                
            } else if (folder3 == "$ cd ..") {
               folderOrder.pop_back();
               currentFolder = folderNames[folderOrder[folderOrder.size() -1]];
            } else if (folder3 == "$ cd /") {
                folderOrder.clear();
                folderOrder.push_back(0);
                currentFolder = "root";
            }
        }
    }

    for (int i = 0; i < folderNames.size(); i++) {
        folderTotal[i] = folderSpaces[i];
        for (int y = 0; y < folderUnder[i].size(); y++) {
            folderTotal[i] = folderTotal[i] + folderSpaces[folderUnder[i][y]];
        }
    }

    
    for (int i = 0; i < folderNames.size(); i++) {
        cout << "\n" << folderNames[i];
        cout << "\n" << folderSpaces[i];
        
/*         cout << "\n";
        for (auto each: folderUnder[i]) {
            cout << each << ", ";
        } */
        cout << "\n" << folderTotal[i];
    }

     for (int i = 0; i < folderNames.size(); i++) {
        if (folderTotal[i] < 100000) {
            cout << "\n" << folderTotal[i];
        }
    }
    
    return 0;
}