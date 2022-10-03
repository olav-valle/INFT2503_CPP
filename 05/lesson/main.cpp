#include <iostream>
#include <memory>

using namespace std;

class A {
public:
  A() {
    cout << "Objektet blir opprettet" << endl;
  }
  ~A() {
    cout << "Objektet blir slettet" << endl;
  }
};

int main() {
  {
    unique_ptr<A> a(new A()); // Det opprettes et anonymt objekt på heapen som a peker til
    // delete a;
  }

  cout << "Scopet er avsluttet" << endl;
}
