#include "surface.hpp" // funksjonen fabs()
#include <cmath>
#include <iostream>
#include <string>

using namespace std;

Surface::Surface(const string &name_, double length_, double width_) : name(name_), length(length_), width(width_) {}

Surface::Surface(double area) : name("ukjent") {
  length = sqrt(area);
  width = length;
}

double Surface::get_area() const {
  return width * length;
}

double Surface::get_circumference() const {
  return 2 * (length + width);
}

int Surface::compare(const Surface &other) const {
  const double toleranse = 0.00001;
  double area1 = get_area();
  double area2 = other.get_area();
  if (fabs(area2 - area1) < toleranse)
    return 0;
  else if (area1 < area2)
    return -1;
  else
    return 1;
}

bool Surface::operator<(const Surface &other) const {
  return (compare(other) < 0);
}

int main() {
  Surface surface1("Flate1", 3, 3);
  Surface surface2("Flate2", 2, 5);

  int res = surface1.compare(surface2);
  if (res == 0)
    cout << "Surfacene er like\n";
  else if (res < 0)
    cout << surface1.name << " er minst\n";
  else
    cout << surface1.name << " er størst\n";

  if (surface1 < surface2)
    cout << surface1.name << " er minst\n";
  if (surface1.operator<(surface2))
    cout << surface1.name << " er minst\n";

  Surface surface3 = 25;
  cout << "Lengde = " << surface3.length << ", width = " << surface3.width << endl;

  surface2 = 50;
  cout << "Lengde = " << surface2.length << ", width = " << surface2.width << endl;
}
