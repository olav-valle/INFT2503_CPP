#include <iostream>
using namespace std;

int find_sum(const int *table, int length);

int main() {
  const int length = 20;
  int numbers[length];
  for (int i = 0; i < length; i++) {
    numbers[i] = i + 1;
  }

  // first 10: start at 0th number, use next 10 numbers
  int first10 = find_sum(numbers, 10);
  cout << first10 << endl;
  cout << "" << endl;

  // next 5: start at 10th number, use next 5 numbers
  int next5 = find_sum(numbers + 10, 5);
  cout << next5 << endl;
  cout << "" << endl;

  // last 5: start at 5th last number, use next 5 numbers
  int last5 = find_sum(numbers + (length - 5), 5);

  cout << last5 << endl;
}

int find_sum(const int *table, int length) {
  int sum = 0;

  for (auto i = 0; i < length; i++) {
    sum += *table;
    cout << *table << endl;
    table++;
  }
  return sum;
}
