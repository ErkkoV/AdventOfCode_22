#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main() {

    string stream;

    ifstream readStream("radioinput.txt");

    string letters = "    "; 
    
    int letterNumber = 0;

    while (getline (readStream, stream)) {
        for (char letter : stream) {
            letterNumber += 1;

            letters = letters.substr(1, 4) + letter; 

            if (letterNumber > 3 && letters[0] != letters[1] && letters[0] != letters[2] && letters[0] != letters[3] && letters[1] != letters[2] && letters[1] != letters[3] && letters[2] != letters[3]) {
                break;
            }
        }
    }

    cout << "\n" << letterNumber;
    cout << "\n" << letters;




    

    
    return 0;
}