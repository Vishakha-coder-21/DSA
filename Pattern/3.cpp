#include <iostream>
using namespace std;

/*
xxxxx
xxxx
xxx
xx
x
*/

int main() {
  int n;
  cin >> n;

  int r = 1;
  while (r <= n) {
    int c = 1;
    while (r + c <= n + 1) {
      cout << "X";
      c += 1;
    }
    cout << endl;
    r += 1;
  }

  // return 0;
}