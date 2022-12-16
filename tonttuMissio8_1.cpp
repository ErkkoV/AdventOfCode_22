#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main() {

    string folder1;
    
    ifstream readFolder1("input8.txt");
    
    int lineHeight = 0;
    bool treeVisibility[99][99];
    int treeHeight[99][99];
    int inviTotal = 0;


    while (getline (readFolder1, folder1)) {
        lineHeight += 1;
        
        for (int i = 0; i < 99; i++) {
            treeVisibility[lineHeight -1][i] = false;
            treeHeight[lineHeight -1][i] = int(folder1[i]) -48;
        }
    }

    
    for (int i = 0; i < 99; i++) {
        for (int y = 0; y < 99; y++) {
            bool invisibleRight = false;
            bool invisibleLeft = false;
            bool invisibleUp = false;
            bool invisibleDown = false;
            
            int height = treeHeight[i][y];
            
            for (int z = 0; z < 99; z++) {
                if (z > y) {
                    if (height <= treeHeight[i][z]) {
                        invisibleRight = true;
                    }
                } else if (z < y) {
                    if (height <= treeHeight[i][z]) {
                        invisibleLeft = true;
                    }
                }
                if (z > i) {
                    if (height <= treeHeight[z][y]) {
                        invisibleUp = true;
                    }
                } else if (z < i) {
                    if (height <= treeHeight[z][y]) {
                        invisibleDown = true;
                    }
                }
            }

            if (invisibleLeft && invisibleRight && invisibleUp && invisibleDown) {
                treeVisibility[i][y] = false;
                inviTotal += 1;
            } else {
                treeVisibility[i][y] = true;
            }
            
        }
    }



    for (int i = 0; i < 99; i++) {
        cout << "\n";
        for (int y = 0; y < 99; y++) {
            cout << treeVisibility[i][y];
        }
    }
    for (int i = 0; i < 99; i++) {
        cout << "\n";
        for (int y = 0; y < 99; y++) {
            cout << treeHeight[i][y];
        }
    }

    cout << "\n \n \n" << (99*99)-inviTotal;

    return 0;
}

