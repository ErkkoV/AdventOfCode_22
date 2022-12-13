#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main() {

    string stack[9];
    
    string moves;

    ifstream readMoves("moveinput.txt");

    int lineNumber = 0;

    while (getline (readMoves, moves)) {
        lineNumber += 1;

        int moveamount;
        int movefrom;
        int moveto;

        if (lineNumber > 0 && lineNumber < 9) {
            
            if (moves[1] != ' ') {
                stack[0] = moves[1] + stack[0];
            }
            if (moves[5] != ' ') {
                stack[1] = moves[5] + stack[1];
            }
            if (moves[9] != ' ') {
                stack[2] = moves[9] + stack[2];
            }
            if (moves[13] != ' ') {
                stack[3] = moves[13] + stack[3];
            }
            if (moves[17] != ' ') {
                stack[4] = moves[17] + stack[4];
            }
            if (moves[21] != ' ') {
                stack[5] = moves[21] + stack[5];
            }
            if (moves[25] != ' ') {
                stack[6] = moves[25] + stack[6];
            }
            if (moves[29] != ' ') {
                stack[7] = moves[29] + stack[7];
            }
            if (moves[33] != ' ') {
                stack[8] = moves[33] + stack[8];
            } 
        } else if (lineNumber > 10) {
            moveamount = stoi(moves.substr(moves.find(" "), moves.find(" ") -1));
            movefrom = stoi(moves.substr(moves.find("from") + 4, moves.find(" ") -1));
            moveto = stoi(moves.substr(moves.find("to") + 2));

            
            string addedStuff = stack[movefrom -1].substr(stack[movefrom -1].length() - moveamount);

            for (int i = addedStuff.length() -1; i > -1; i--) {
                 stack[moveto -1] = stack[moveto -1] + addedStuff[i];
            }
            
           stack[movefrom -1] = stack[movefrom -1].substr(0, stack[movefrom -1].length() - moveamount);

        }

    }

    cout << "\n" << stack[0];
    cout << "\n" << stack[1];
    cout << "\n" << stack[2];
    cout << "\n" << stack[3];
    cout << "\n" << stack[4];
    cout << "\n" << stack[5];
    cout << "\n" << stack[6];
    cout << "\n" << stack[7];
    cout << "\n" << stack[8];

    

    return 0;
}