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
    int bestScore = 0;

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

            int height = treeHeight[i][y];
            
            int viewRight = 0;
            int viewLeft = 0;
            int viewDown = 0;
            int viewUp = 0;
            
            
            for (int z = 1; z < 99; z++) {
                if (y == 98) {
                    break;
                } else if (y + z == 98) {
                    viewRight +=1;
                    break;
                } else if(height > treeHeight[i][y+z]) {
                    viewRight +=1;
                } else {
                    viewRight +=1;
                    break;
                }
            }
            for (int z = 1; z < 99; z++) {
                if (y == 0) {
                    break;
                } else if (y - z == 0) {
                    viewLeft +=1;
                    break;
                } else if(height > treeHeight[i][y-z]) {
                    viewLeft +=1;
                } else {
                    viewLeft +=1;
                    break;
                }
            }
            for (int z = 1; z < 99; z++) {
                if (i == 98) {
                    break;
                } else if (i + z == 98) {
                    viewDown +=1;
                    break;
                } else if(height > treeHeight[i+z][y]) {
                    viewDown +=1;
                } else {
                    viewDown +=1;
                    break;
                }
            }
            for (int z = 1; z < 99; z++) {
                if (y == 0) {
                    break;
                } else if (i - z == 0) {
                    viewUp +=1;
                    break;
                } else if(height > treeHeight[i-z][y]) {
                    viewUp +=1;
                } else {
                    viewUp +=1;
                    break;
                }
            }

            int best = viewUp * viewDown * viewLeft * viewRight;
            if (best > bestScore) {
                cout << "\n";
                cout << "\n" << viewUp;
                cout << "\n" << viewDown;
                cout << "\n" << viewLeft;
                cout << "\n" << viewRight;

                bestScore = best;
            }
        }
    }


    cout << "\n \n \n" << bestScore;

    return 0;
}

