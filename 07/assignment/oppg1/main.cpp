#include "fraction.hpp"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
  cout << text << broek.numerator << " / " << broek.denominator << endl;
}

// Overrides << operator of ostream, creating an overload
// specifically for Fraction type arguments.
// This lets us use << to print a fraction,
// instead of the print() function we defined above.
ostream &operator<<(ostream &out, const Fraction &fraction) {
  out << fraction.numerator << "/" << fraction.denominator;
  return out;
}

int main() {

  Fraction fraction1(2, 3);
  Fraction fraction2 = 3 + fraction1;
  Fraction fraction3 = fraction2 + 4;
  print("fraction1 = ", fraction1);
  print("fraction2 = ", fraction2);
  print("fraction3 = ", fraction3);

  // test assignment 1a
  print("fraction1 - 3 = ", (fraction1 - 2));
  print("3 - fraction1 = ", (3 - fraction1));

  // assignment 1b
  // Tolkning: Uttrykket leses fra venstre mot høyre, og følgende versjoner av - operator brukes:
  // 1. 5 - 3 bruker vanlig integer - operator, som gir int i retur
  // 2. 2 - fraction1 bruker vår egendefinerte (ikkemedlemfunksjon) for (int - Fraction), som gir ny Fraction i retur
  // 3. egendefinert ikkemedlemfunksjon for (Fraction - int) brukes, som gir ny Fractoin i retur
  // 4. vi har nå (Fraction - Fraction), og kan bruke - operatoren vi laget for Fraction
  print("assignment 1b: ", (5 - 3 - fraction1 - 7 - fraction2));

  Fraction a(10, 20);
  Fraction b(3, 4);
  Fraction c;
  c.set(5);
  Fraction d = a / b;

  cout << "A = " << a << endl;
  print("a = ", a);
  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  b += a;
  ++c;
  d *= d;

  print("b = ", b);
  print("c = ", c);
  print("d = ", d);

  c = a + b - d * a;
  c = -c;

  print("c = ", c);

  if (a + b != c + d)
    cout << "a + b != c + d" << endl;
  else
    cout << " a + b == c + d" << endl;
  while (b > a)
    b -= a;
  print("b = ", b);
}
