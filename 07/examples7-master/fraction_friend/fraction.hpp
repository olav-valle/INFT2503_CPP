#pragma once

#include <ostream>

class Fraction {
public:
  int numerator;
  int denominator;

  Fraction();
  Fraction(int numerator, int denominator);
  void set(int numerator_, int denominator_ = 1);
  friend std::ostream &operator<<(std::ostream &out, const Fraction &fraction);

private:
  void reduce();
};
