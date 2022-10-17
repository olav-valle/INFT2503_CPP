#include "set.hpp"
#include <iostream>
using namespace std;
int main() {
  cout << "create empty set_a: " << endl;

  Set set_a;
  cout << "set_a (empty): " << set_a << endl;

  // test using += as insert operation
  set_a += 1;
  set_a += 2;
  set_a += 3;
  set_a += 4;
  set_a += 5;
  set_a += 6;

  cout << "set_a is now = {1,2,3,4,5,6} " << endl;
  cout << "set_a: " << set_a << endl;

  // test creating set from existing set
  cout << "copy set_a into set_b " << endl;
  Set set_b(set_a);

  cout << "set_b: " << set_b << endl;

  Set set_c;
  set_c += 1; // check for not inserting double elements on union with set_a
  set_c += 7;
  set_c += 8;
  cout << "set_c: " << set_c << endl;

  // Seems like a bad hack, but ok..? https://en.cppreference.com/w/cpp/io/manip/boolalpha
  std::cout.setf(std::ios::boolalpha);
  Set set_d = set_a + set_c;
  cout << "set_d, union of set_a and set_c: " << set_d << endl;
  cout << "set_d contains element 1 from set_a and set_c: " << set_d.exists(1) << endl;
  cout << "set_d contains element 2 from set_a: " << set_d.exists(2) << endl;
  cout << "set_d contains element 7 from set_c: " << set_d.exists(2) << endl;
  cout << "set_d does not contain 0 : " << !set_d.exists(0) << endl;
}
