#include <cctype>
#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

void read_temperatures(double temperatures[], int length);

int main() {
  const int length = 5;

  int lowTemp = 10; // < 10
  int lowCount = 0; // < 10

  int midCount = 0; // [10,20]

  int highTemp = 20; // > 20
  int highCount = 0; // > 20

  double temperatures[length];
  read_temperatures(temperatures, length);

  for (int i = 0; i < length; i++) {
    double temp = temperatures[i];
    cout << "Temperatur nr. " << i + 1 << ": " << temp << endl;

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

void read_temperatures(double temperatures[], int length) {
  const char fileName[] = "temps.dat";
  ifstream file;
  file.open(fileName);

  if (!file) {
    cout << "Error opening file" << fileName << endl;
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < length; i++) {
    file >> temperatures[i];
  }
}
