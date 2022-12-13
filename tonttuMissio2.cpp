#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
using namespace std;

int getScore(char player, char opponent) {
        int score = 0;
        if (player == 'X') {
            score += 1;
            if (opponent == 'A') {
                    score += 3;
            } else if (opponent == 'C') {
                    score += 6;
            }
        } else if (player == 'Y') {
            score += 2;
            if (opponent == 'B') {
                    score += 3;
            } else if (opponent == 'A') {
                    score += 6;
            }
        } else if (player == 'Z') {
            score += 3;
            if (opponent == 'C') {
                score += 3;
            } else if (opponent == 'B') {
                score += 6;
            }
        }

        return score;
    }

    int charScore(char opp) {
        if (opp == 'A') {
            return 1;
        } else if (opp == 'B') {
            return 2;
        } else if (opp == 'C') {
            return 3;
        }
    };

    char oppositeWin(char choice) {
        if (choice == 'A') {
            return 'B';
        } else if (choice == 'B') {
            return 'C';
        } else if (choice == 'C') {
            return 'A';
        }
    }

    char oppositeLose(char choice) {
        if (choice == 'A') {
            return 'C';
        } else if (choice == 'B') {
            return 'A';
        } else if (choice == 'C') {
            return 'B';
        }
    }

    int getScore2(char opponent, char condition) {
        int score = 0;

        if (condition == 'X') {
            score += 0;
            score += charScore(oppositeLose(opponent));
        } else if (condition == 'Y') {
            score += 3;
            score += charScore(opponent);
        } else if (condition == 'Z') {
            score += 6;
            score += charScore(oppositeWin(opponent));
        }

        return score;
    }


int main() {
    string rpsList;
    
    ifstream readGuide("rpslist.txt");

    int finalScore = 0;

    while (getline (readGuide, rpsList)) {
        finalScore += getScore2(rpsList[0], rpsList[2]);
    }

    cout << finalScore;


    return 0;
}