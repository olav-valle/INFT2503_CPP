#include <iostream>
using namespace std;

int main() {
  int v1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  int v2[10];

  cout << "size & type of v1[10]:" << endl;
  cout << sizeof(v1) << endl;
  cout << typeid(v1[0]).name() << endl;
  // The C++ range-for loop, basically a for-each
  // No need to specify array bounds, ends when array ends
  // for (auto x : v1) {
  //   v2[x] = x;
  // }

  // for (auto x : v2) {
  //   cout << x << '\n';
  // }

  double d1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  cout << "size & type of d[10]:" << endl;
  cout << sizeof(d1) << endl;
  cout << typeid(d1).name() << endl;
  // invalid range expression of type 'int'; no viable 'begin' function available
  //  int v3 = 5;
  //  for (auto x : v3) {
  //  cout << x << '\n';
  // }

  int i = 3;
  int j = 5;
  int *p = &i; // addr. of i
  int *q = &j; // addr. of j

  std::cout << "i: " << i << endl;
  std::cout << "&i is addr. of i: " << &i << endl;

  std::cout << "*p points to content of i: " << *p << endl;
  std::cout << "&p is addr. of pointer p: " << &p << endl;
  bool ip = **&p != *&i;
  std::cout << "&p != &i: " << ip << endl;

  std::cout << "p is addr. of what p points to (i): " << p << endl;

  std::cout << "j: " << j << endl;

  std::cout << "*q: " << *q << endl;

  std::cout << "Hello, world!\n";
}
