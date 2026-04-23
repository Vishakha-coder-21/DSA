/*
	A person wants to go from origin to a
	particular location, he can move in only
	4 directions(i.e. East, West, North, South)
	but his friend gave him a long route, help a
	person to find minimum Moves so that he can
	reach to the destination.

	Input  1 – NESNWES
	Output 1 – E

	You need to print the lexicographically(dic order)
	sorted string. Assume the string will have only
	‘E’ ‘N’ ‘S’ ‘W’ characters.


	Input  2 – SSSNEEEW
	Output 2 – EESS

*/

#include<iostream>
using namespace std;


int main() {

	char ch;
	int x{0}, y{0};

	while (cin >> ch) {
		if (ch == 'N') {
			y += 1;
		} else if (ch == 'S') {
			y -= 1;
		} else if (ch == 'E') {
			x += 1;
		} else {
			x -= 1;
		}
	}

	// cout << x << " " << y << endl;


	if (x > 0) {
		//This means you have a East in your answer.

		//Print out the East Direction.
		int c = 1;
		while (c <= x) {
			cout << 'E';
			c += 1;
		}

		if (y > 0) {
			//You have a North Direction in your answer.

			//Print Out the North Direction.
			int c = 1;
			while (c <= y) {
				cout << 'N';
				c += 1;
			}

		} else {
			//You have South Direction in your answer.

			//Print out the South Direction.
			y = y * (-1);
			int c = 1;
			while (c <= y) {
				cout << 'S';
				c += 1;
			}
		}


	} else {
		//This means you have West in your answer.

		if (y > 0) {
			//You have a North Direction in your answer.

			//Print Out the North Direction.
			int c = 1;
			while (c <= y) {
				cout << 'N';
				c += 1;
			}

		} else {
			//You have South Direction in your answer.

			//Print out the South Direction.
			y = y * (-1);
			int c = 1;
			while (c <= y) {
				cout << 'S';
				c += 1;
			}
		}

		//Print out the West Direction.
		x = x * (-1);
		int c = 1;
		while (c <= x) {
			cout << 'W';
			c += 1;
		}
	}


}
