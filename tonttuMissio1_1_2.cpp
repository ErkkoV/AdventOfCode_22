#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    string foodList;
    
    ifstream readFood("foodlist.txt");

    int food = 0;
    int finalFood1 = 0;
    int finalFood2 = 0;
    int finalFood3 = 0;
    
    while (getline (readFood, foodList)) {
        if (foodList == "") {
          food = 0;
        } else {
          food += stoi(foodList);
        }
        if (finalFood1 < food) {
          finalFood3 = finalFood2;
          finalFood2 = finalFood1;
          finalFood1 = food;
        } else if (finalFood2 < food) {
          finalFood3 = finalFood2;
          finalFood2 = food;
        } else if (finalFood3 < food) {
            finalFood3 = food;
        }
    }

    int finalResult = finalFood1 + finalFood2 + finalFood3; 

    // result for 1
    cout << "\n" << finalFood1;

    // result for 2
    cout << "\n" << finalResult;

    return 0;
}