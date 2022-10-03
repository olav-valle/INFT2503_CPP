//
// example1.cpp
//
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Material {
public:
  string name;
  double price; // per unit

  Material(const string &name_, double price_) : name(name_), price(price_) {}

  virtual void print() const {
    cout << "Navn: " << name << endl
         << "Pris: " << price << endl;
  };
};

class Covering : public Material {
public:
  double width; // I meter.

  // Prisen er per meter belegg (i lengden)
  Covering(const string &name, double price, double width_) : Material(name, price), width(width_) {}

  void print() const override {
    Material::print();
    cout << "For belegg" << endl
         << "Bredde: " << width << endl;
  }
};

class Wallpaper : public Material {
public:
  double length; // i meter per rull
  double width;  // i meter per rull

  // Prisen er per rull
  Wallpaper(const string &name, double price, double length_, double width_)
      : Material(name, price), length(length_), width(width_) {}

  void print() const override {
    Material::print();
    cout << "For tapet" << endl
         << "Bredde av rull: " << width << endl
         << "Lengde av rull: " << length << endl;
  }
};

class Paint : public Material {
public:
  int coatings;         // Antall strøk
  double liters_per_m2; // Liter per kvadratmeter

  // Prisen er per liter
  Paint(const string &navn, double pris, int coatings_, double liters_per_m2_)
      : Material(navn, pris), coatings(coatings_), liters_per_m2(liters_per_m2_) {}

  void print() const override {
    Material::print();
    cout << "For maling" << endl
         << "Antall strøk: " << coatings << endl
         << "liter per kvadratmeter: " << liters_per_m2 << endl;
  }
};

int main() {

  vector<unique_ptr<Material>> materials;
  materials.emplace_back(new Covering("Super Duper Dux", 433.50, 4));
  materials.emplace_back(new Wallpaper("Soldogg", 200, 12, 0.6));
  materials.emplace_back(new Paint("Extra", 125, 2, 12.0));

  for (auto &material : materials) {
    material->print();
    cout << endl;
  }

  // Dynamic casting using dynamic_cast to type check elements in container
  cout << "Malinger lagret i materials vektoren:" << endl;
  for (auto &material : materials) {
    if (dynamic_cast<Paint *>(material.get()))
      material->print();
  }

  // Objektet bruker sin egen print()-funksjon (ingen arv)
  // covering.print();
  // cout << endl;
  // wallpaper.print();
  // cout << endl;
  // paint.print();
}

// Utskrift:
// Navn: Super Duper Dux
// Pris: 433.5
// For belegg
// Bredde: 4

// Navn: Soldogg
// Pris: 200
// For tapet
// Bredde av rull: 0.6
// Lengde av rull: 12

// Navn: Extra
// Pris: 125
// For maling
// Antall strøk: 2
// liter per kvadratmeter: 12
