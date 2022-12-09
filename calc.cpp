#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

ofstream MyFile("results.txt");

int compare(int a, int b) {
    int result = (a > b) ? 1 : 0;
    return result;
}

int main() {

    const int die[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int result = 0;

    for (int a : die) {
      for (int d : die) {
        result += compare(a, d);
      }
    }

    

    cout << result;

    return 0;
}