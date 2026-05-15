// Convert only 1st ch

#include <iostream>
using namespace std;

int main() {
  char ch;
  cin.get(ch);

  if (ch >= 97 and ch <= 122) {
    ch -= 32;
  }
  cout << ch;

  while (cin.get(ch)) {
    cout << ch;
  }
}