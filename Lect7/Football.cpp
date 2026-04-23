#include<iostream>
using namespace std;


int main() {

	char ch;
	int Count0 = 0, Count1 = 0;

	int prev_character = -1; //Initially it is -1 why because initially we don't have a prev character so wanted to assign a value that is not part of answer.

	/*
		prev_character == 0 this means previous character was 0.
		prev_character == 1 this means previous character was 1.

	*/


	while (cin >> ch) {

		if (ch == '0') {

			//Current Character is 0.

			if (prev_character == 0 or prev_character == -1) {

				Count0 += 1;

				//Check if you have 7 consecutive values of 0.
				if (Count0 >= 7) {
					cout << "Yes" << endl;
					return 0;
				}

			} else {

				//Prev character is 1 and current character is 0.
				Count0 = 1;

			}


			/*
				Current Character is 0 and hence for the next character
				prev_character should be 0 as current character is 0.
			*/
			prev_character = 0;



		} else {

			//Current Character is 1.

			if (prev_character == 1 or prev_character == -1) {

				Count1 += 1;

				//Check if you have 7 consecutive values of 1.
				if (Count1 >= 7) {
					cout << "Yes" << endl;
					return 0;
				}

			} else {

				//Prev character is 0 and current character is 1.
				Count1 = 1;

			}


			/*
				Current Character is 1 and hence for the next character
				prev_character should be 1 as current character is 1.
			*/
			prev_character = 1;

		}

	}

	//If I am Standing Here the program has not stopped using return 0 statement hence it means we have not found a yes answer so my answer is No.

	cout << "No" << endl;

}
