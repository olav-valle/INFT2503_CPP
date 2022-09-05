#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  const int length = 5;

  int low; // < 10
  int mid; // [10,20]
  int high; // > 20
  
  cout << "Du skal skrive inn 5 temperaturer." << endl;

  double temp;

  for (int i = 0; i < length; i++) {
    cout << "Temperature " << i << ": " << endl;
    cin >> temp;
    
  }
}
