#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  const int length = 5;

  int lowTemp = 10; // < 10
  int lowCount = 0; // < 10

  int midCount = 0; // [10,20]

  int highTemp = 20; // > 20
  int highCount = 0; // > 20

  cout << "Du skal skrive inn 5 temperaturer." << endl;

  double temp;

  for (int i = 0; i < length; i++) {
    cout << "Temperatur nr. " << i + 1 << ": ";
    cin >> temp;

    if (temp < lowTemp) { // less than 10
      lowCount++;
    } else if (temp > highTemp) { // above 20
      highCount++;
    } else { // must be between 10 and 20, inclusive
      midCount++;
    }
  }
  cout << "Antall under 10 er " << lowCount << endl;
  cout << "Antall mellom 10 og 20 er " << midCount << endl;
  cout << "Antall over 20 er " << highCount << endl;
}
