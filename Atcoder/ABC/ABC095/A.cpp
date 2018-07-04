#include <iostream>
using namespace std;

int main() {
  string s;
  cin >> s;
  int cost = 700;
  for (int i = 0; i < 3; i++) {
    if (s[i] == 'o') cost += 100;
  }
  cout << cost;
  return 0;
}
