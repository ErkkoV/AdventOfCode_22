#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main() {

    string stream;

    ifstream readStream("radioinput.txt");

    string letters = "              "; 
    
    int letterNumber = 0;

    while (getline (readStream, stream)) {
        for (char letter : stream) {
            letterNumber += 1;

            letters = letters.substr(1, 14) + letter;

            int match = 0;

            if (letterNumber > 13) {
                for (char each1 : letters) {
                    for (char each2: letters) {
                        if (each1 == each2) {
                            match += 1;
                        }
                    }
                }
                if (match < 15) {
                    break;
                }
            }


            
        }
    }

    cout << "\n" << letterNumber;
    cout << "\n" << letters;




    

    
    return 0;
}