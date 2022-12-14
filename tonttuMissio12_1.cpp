#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

int main() {

    string folder1;
    
    ifstream readFolder1("input12.txt");
    
    int lineHeight = 0;
    int lineWidth; 
    int startpoint[2];
    int endpoint[2];
    int elevations[41][132];
    int distance[41][132];
    int currentDistance = 0;

    while (getline (readFolder1, folder1)) {
        lineHeight += 1;
        lineWidth = folder1.length();
        
        for (int i = 0; i < folder1.length(); i++) {
            elevations[lineHeight -1][i] = int(folder1[i]);
            distance[lineHeight -1][i] = -1;

            if (folder1[i] == 'S') {
                startpoint[0] = lineHeight -1;
                startpoint[1] = i;
                elevations[lineHeight -1][i] = 97;
                distance[lineHeight -1][i] = 0;
            }
            if (folder1[i] == 'E') {
                endpoint[0] = lineHeight -1;
                endpoint[1] = i;
                elevations[lineHeight -1][i] = 122;
            }
            
        }
    }

    while (distance[endpoint[0]][endpoint[1]] == -1) {
        for (int i = 0; i < 41; i++) {
            for (int y = 0; y < 132; y++) {
                if (distance[i][y] == currentDistance) {
                    // rightcheck
                    if (y !=131 && distance[i][y+1] < 1 && elevations[i][y+1] <= elevations[i][y] +1) {
                        distance[i][y+1] = currentDistance + 1;
                    }
                    // leftcheck
                    if (y !=0 && distance[i][y-1] < 1 && elevations[i][y-1] <= elevations[i][y] +1) {
                        distance[i][y-1] = currentDistance + 1;
                    }
                    // downcheck
                    if (i !=40 && distance[i+1][y] < 1 && elevations[i+1][y] <= elevations[i][y] +1) {
                        distance[i+1][y] = currentDistance + 1;
                    }
                    // upcheck
                    if (i !=0 && distance[i-1][y] < 1 && elevations[i-1][y] <= elevations[i][y] +1) {
                        distance[i-1][y] = currentDistance + 1;
                    }
                }
            }
        }
        currentDistance += 1;
    }
    

    cout << "\n \n \n" << distance[endpoint[0]][endpoint[1]];

   return 0;
}

