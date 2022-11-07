#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// borrowed from lesson examples:
ostream &operator<<(ostream &out, const vector<int> &table) {
  for (auto &e : table)
    out << e << " ";
  return out;
}

int main() {
  vector<int> v1 = {3, 3, 12, 14, 17, 25, 30};
  vector<int> v2 = {2, 3, 12, 14, 24};

  // a) Find first element in v1 larger than 15 using find_if
  // https://en.cppreference.com/w/cpp/algorithm/find
  auto i1 = find_if(v1.begin(), v1.end(), [](int val) {
    return val > 15;
  });
  cout << "value is: " << *i1 << " index is: " << (i1 - v1.begin()) << endl;

  // b) define "approximately equal" as abs(a - b) <= 2.
  // find if interval [v1.begin(), v1.begin() + 5) and v2 are equal in this sense.
  // do same for interval [v1.begin(), v1.begin() + 4) and v2. Use algorithm "equal" from stl.
  // https://en.cppreference.com/w/cpp/algorithm/equal

  // equal returns single boolean saying if ALL elements passed predicate
  bool eq1 = equal(v1.begin(), v1.begin() + 5, v2.begin(), [](int val1, int val2) {
    return (abs(val1 - val2) <= 2);
  });
  cout << "intervals are " << (eq1 ? "equal" : "not equal") << endl;

  bool eq2 = equal(v1.begin(), v1.begin() + 4, v2.begin(), [](int val1, int val2) {
    return (abs(val1 - val2) <= 2);
  });
  cout << "intervals are " << (eq2 ? "equal" : "not equal") << endl;

  // c) replace all odd numbers in v1 with 100 using replace_copy_if
  // https://en.cppreference.com/w/cpp/algorithm/replace_copy
  replace_copy_if(
      v1.begin(), v1.end(), v1.begin(), [](int val) {
        // odd defined as not divisible by two
        return (val % 2 != 0);
      },
      100);
  cout << v1 << endl;
}
