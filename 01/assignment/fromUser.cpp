#include <cctype>
#include <cstring>
#include <iostream>
using namespace std;

int main() {
  const int length = 5;

  double temps[length];
//todo: how to define size of double[]?
  cout << "Du skal skrive inn 5 temperaturer." << endl;

  for (int i = 0; i < length; i++) {
    cin >> temps;  
  }
}
