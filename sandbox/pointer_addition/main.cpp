#include <fstream>
#include <iostream>
#include <memory>
using namespace std;

int main() {

  char *s = "hi";
  cout << s;
  unique_ptr<int> z; // Create empty unique pointers
  unique_ptr<int> q;
  unique_ptr<int> x;
  z = make_unique<int>(16); // Allocate int (16) on heap. Only one reference allowed.
  x = make_unique<int>(16);
  q = move(z); // Move reference from z to q.
  if (z == nullptr) {
    cout << "Z null";
  }
  cout << *q;
  cout << *x;

  // const int m = 5;
  // int ints[m];
  // double floats[m];

  // int *p;
  // cout << << endl;
  // cout << "heltallsadresser:\n";
  // // Adressene skrives ut på heksadesimal form.
  // for (int i = 0; i < m; i++)
  //   cout << (ints + i) << endl;

  // cout << "\nflyttallsadresser:\n";
  // for (int i = 0; i < m; i++)
  //   cout << (floats + i) << endl;
}
