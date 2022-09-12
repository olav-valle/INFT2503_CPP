#include <iostream>

int main() {
  // find the syntax errors in following code and correct them
  //  int a = 5;
  //  int &b;         // uninitialized ref
  //  int *c;
  //  c = &b;
  //  *a = *b + *c;   // a is not initialized as a pointer, b is not a pointer but a ref
  //  &b = 2;         // refs cannot be re-assigned, and '2' would not be valid anyway.

  // Corrected code
  int a = 5;
  int &b = a; // a is the only available thing we can reference
  int *c;
  c = &b;
  a = b + *c; // a == 10
  b = 2;      // a == 2
}
