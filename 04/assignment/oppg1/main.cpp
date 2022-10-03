#include <algorithm>
#include <iostream>
#include <vector>
// Oppgave 4.1
// Lag et lite program:

// Opprett en vektor av double. Legg inn fem tall (behøver ikke leses inn.)

// Prøv ut medlemsfunksjonene front() og back().
// De returnerer hver et element,og de har ingen argumenter.

// Bruk emplace() til å sette inn et tall etter det første elementet.
// Skriv ut resultatet av front() etterpå.

// Prøv ut STL-algoritmen find(). Den tar tre argumenter: start, slutt og søkeverdi.
// De to første er iteratorer til søkeintervallet.
// Funksjonen returnerer en iterator til den funne verdien, hvis den finnes.
// Hvis den ikke finnes, er returverdien lik end()-iteratoren.
// Lag et if-uttrykk som sjekker om resultatet av find() er vellykket eller ikke,
// og dersom resultatet var vellykket, skriv ut den funne verdien.

using namespace std;
int main() {
  vector<int> v1{0, 1, 2, 3, 4};
  cout << "vector v1 { ";
  for (auto n : v1) {
    cout << n << ", ";
  }
  cout << "}\n";

  cout << "Trying out front(), back() and emplace():" << endl;
  cout << "vector.front(): " << v1.front() << endl;
  cout << "vector.back(): " << v1.back() << endl;
  cout << "inserted " << *(v1.emplace(v1.begin() + 1, -1)) << " as second entry using emplace() " << endl;
  cout << "new vector v1 { ";
  for (auto n : v1) {
    cout << n << ", ";
  }
  cout << "}\n";
  cout << "vector.front(): " << v1.front() << endl;
  cout << "vector.back(): " << v1.back() << endl;
  cout << "v1[1] (second element): " << v1[1] << endl;
  cout << "\n";

  cout << "Checking if element exists in vector:" << endl;
  vector<int>
      v2{10, 20, 30, 40, 50};
  cout << "vector v2 { ";
  for (auto n : v2) {
    cout << n << ", ";
  }
  cout << "}\n";

  int search_val = 10;
  auto result = find(v2.begin(), v2.end(), search_val);
  cout << "Searching for " << search_val << " in vector v2:" << endl;
  // Why use if statements when we can use ternary operators? 8~D
  (result != v2.end()) // find returns end-iterator if failed.
      ? cout << *result << " was found in vector." << endl
      : cout << search_val << " not found in vector" << endl;
}
