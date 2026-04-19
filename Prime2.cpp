#include<iostream>
using namespace std;


int main() {

	int n;
	cin >> n;

	int c = 2;

	while (c <= n - 1) {

		if ((n % c) == 0) {
			break;
		}
		c += 1;
	}

	if (c <= n - 1) {
		cout << "Not Prime" << endl;
	} else {
		cout << "Prime" << endl;
	}
}

