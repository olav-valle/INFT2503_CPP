#include "fraction.hpp"
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Fraction::Fraction(int numerator, int denominator) {
  set(numerator, denominator);
}

void Fraction::set(int numerator_, int denominator_) {
  if (denominator_ != 0) {
    numerator = numerator_;
    denominator = denominator_;
    reduce();
  } else {
    throw "nevneren ble null";
  }
}

//-------------------------------------------------------------------
//
// Sørg for at nevneren alltid er positiv, og brøken mest mulig
// forkortet. Bruker Euclids algoritme for å finne fellesnevneren.
//
void Fraction::reduce() {
  if (denominator < 0) {
    numerator = -numerator;
    denominator = -denominator;
  }
  int a = numerator;
  int b = denominator;
  int c;
  if (a < 0)
    a = -a;

  while (b > 0) {
    c = a % b;
    a = b;
    b = c;
  }
  numerator /= a;
  denominator /= a;
}
