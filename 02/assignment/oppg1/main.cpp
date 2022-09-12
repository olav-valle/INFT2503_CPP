#include <iostream>
using namespace std;

int main() {
  int i{3};
  int j{5};

  int *p{&i};
  int *q{&j};

  cout << "i" << endl;
  cout << i << endl;
  cout << &i << endl;

  cout << "j" << endl;
  cout << j << endl;
  cout << &j << endl;

  cout << "p" << endl;
  cout << p << endl;
  cout << *p << endl;
  cout << &p << endl;

  cout << "q" << endl;
  cout << q << endl;
  cout << *q << endl;
  cout << &q << endl;

  *p = 7; // i == 7
  cout << *p << endl;

  *q += 4; // j == 9
  cout << *q << endl;

  *q = *p + 1; // j == 8
  cout << *q << endl;

  p = q; // *p == *q, i.e. *p == j == 8. i == 7, unchanged
  cout << *p << " " << *q << endl;
  cout << i << " " << j << endl;
}
