#pragma once

#include <string>

using namespace std;

class Commodity {
public:
  Commodity(const string &name_, int id_, double price_);

  const string &get_name() const { return name; }
  int get_id() const { return id; }
  double get_price() { return price; }
  double get_price(double qty) { return price * qty; }
  double get_price_with_sales_tax(double qty);
  void set_price(double price_);

private:
  string name;
  int id;
  double price;
};
