#include "commodity.hpp"
#include <iostream>
#include <string>

using namespace std;

const double tax = 1.25;

Commodity::Commodity(const string &name_, int id_, double price_)
    : name(name_), id(id_), price(price_) {}

// double Commodity::get_price(double qty) {
//   return price * qty;
// }

double Commodity::get_price_with_sales_tax(double qty) {
  return price * qty * tax;
}

void Commodity::set_price(double price_) {
  price = price_;
}
