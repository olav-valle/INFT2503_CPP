#include "set.hpp"

Set::Set() {}

// check if element exists in Set
bool Set::exists(int other_element) const {
  // again, we get warning to use size_t because vector uses size_t..?
  for (size_t i = 0; i < elements.size(); i++) {
    if (elements[i] == other_element)
      return true;
  }
  return false;
}

// union of sets
Set Set::operator+(const Set &other_set) const {
  Set set = *this;
  for (size_t i = 0; i < other_set.elements.size(); i++) {
    auto other_element = other_set.elements[i];
    set += other_element;
  }
  return set;
}

// add element to set
Set &Set::operator+=(int element) {
  if (!exists(element)) {
    elements.emplace_back(element);
  }
  return *this;
}

// get element at index
int Set::operator[](size_t index) const {
  return elements[index];
}

// other possible operations:
// construct from vector/array?
// insert element(s) from vector/array?
// intersection
// difference (!exists in both sets, or something)
// test for sub/super set..?
// ...?

std::ostream &operator<<(std::ostream &out, const Set &set) {
  for (size_t i = 0; i < set.elements.size(); i++)
    out << set[i] << " ";
  return out;
}
