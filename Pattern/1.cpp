#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int r = 1;

  while (r <= n) {
    int c = 1;
    while (c <= r) {
      cout << "X";
      c += 1;
    }
    cout << endl;
    r += 1;
  }
}