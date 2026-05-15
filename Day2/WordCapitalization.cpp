#include <iostream>
using namespace std;

int main() {
  char ch;

  while (cin.get(ch)) {
    if (ch >= 97 and ch <= 122) {
      ch -= 32;
    } else if (ch >= 65 and ch <= 90) {
      ch += 32;
    }
    cout << ch;
  }
}