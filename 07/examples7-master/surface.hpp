#pragma once

#include <string>

class Surface {
public:
  std::string name; // til identifikasjon
  double length;
  double width;

  Surface(const std::string &name_, double length_, double width_);
  Surface(double area); // name blir "ukjent", bredde = lengde = sqrt(areal)

  double get_area() const;
  double get_circumference() const;

  int compare(const Surface &other) const;
  bool operator<(const Surface &other) const;
};
