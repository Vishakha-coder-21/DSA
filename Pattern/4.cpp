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

    while (c <= n) {
      if (r <= c) {
        cout << "X";
        // c+=1;
      } else {
        cout << " ";
        // c+=1;
      }

      c += 1;
    }

    cout << endl;
    r += 1;
  }
}