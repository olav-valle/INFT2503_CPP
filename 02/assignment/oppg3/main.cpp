#include <iostream>

using namespace std;

int main() {
  // Find possible errors/failures in the following code

  char text[5];
  char *pointer = text;
  char search_for = 'e'; // only matches to lower-case "e". Fine if you want that.
  cin >> text;           // input can be longer than 5 chars.
  cout << *pointer;
  while (*pointer != search_for) { // will never end if 'e' is not found...
    *pointer = search_for;         // overwrites char in *pointer, which seems weird..?
    pointer++;                     // increments past pointer + 5
  }
}
