#include <iostream>

using namespace std;

int main() {
  double number = 1.1;
  double *p;
  p = &number;
  double &r = number;

  // three ways to get the value of number:
  cout << number << endl; // using the variable itself
  cout << *p << endl;     // using the value of the object that pointer p points to
  cout << r << endl;      // using the reference r, which refers to the variable 'number'
}
