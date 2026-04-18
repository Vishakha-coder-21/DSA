#include<iostream>
using namespace std;

int main() {

	int n;
	cin >> n;

	int c = 2;

	while (c <= n - 1) {

		if ((n % c) == 0) {
			cout << "Not Prime" << endl;
			return 0;
		}

		c += 1;
	}

	cout << "Prime" << endl;
}
