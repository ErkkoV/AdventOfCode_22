#include <iostream>
#include <string>
using namespace std;

  class Drink {
    public:
      string type;
      int amount;
      bool drinkCheck(int value) {
        if (value >= amount && value < amount + 3) {
            return true;
        } else {
            return false;
        }
      }
  };

int main() {
  string answer;

  string start;
  
  int howMuch;
  
  Drink kahvi;
  kahvi.type = "kahvia";
  kahvi.amount = 3;
  Drink energia;
  energia.type = "energiavetta";
  energia.amount = 0;
  Drink redbull;
  redbull.type = "redbullia";
  redbull.amount = 2;

  cout << "Tervetuloa toniPal-peliin!\nOletko valmis? (kylla/ei)\n";

  cin >> start;

  if (start != "kylla") {
    cout << "\nPelkuri!";
  }

  while (start == "kylla")
    {
      cout << "\nMitä toniPal juo? ";

      cin >> answer;

      if (answer == kahvi.type || answer == energia.type || answer == redbull.type) {
        cout << "Oikein! \n" << "ToniPal juo " << answer;
      
        cout << "\nMonta " << answer << " toniPal juo päivässä? ";

        cin >> howMuch;

        string amount;

        if (answer == kahvi.type) {
            amount = (kahvi.drinkCheck(howMuch)) ? "Oikein! ToniPal juo " : "Väärin! Tonipal ei juo ";
        } else if (answer == redbull.type) {
            amount = (redbull.drinkCheck(howMuch)) ? "Oikein! ToniPal juo " : "Väärin! Tonipal ei juo ";
        } else {
            amount = (energia.drinkCheck(howMuch)) ? "Oikein! ToniPal juo " : "Väärin! Tonipal ei juo ";
        }

        cout << "\n" << amount << howMuch << " " << answer <<  " päivässä";

        if (amount == "Oikein! ToniPal juo ") {
            break;
        }
      
      } else {
        cout << "Väärin! \n" << "ToniPal juo " << energia.type << ", " << kahvi.type << " tai " << redbull.type;
      }
    }

    if (start == "kylla") {
      cout << "\nOnneksi olkoon! Voitit toniPal-pelin.\n";
      int i = 0;
      
      while (i < 10) {
        cout << "\nASD";
        i++;
      }
    }
  
    return 0;
};