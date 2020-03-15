#include<iostream>

using namespace std;

int main(void) {

	int a;
	cin >> a;

	if ( 100 >= a&&a >= 90) {
		cout << "A";
	}
	else if (89 >= a&&a >= 80) {
		cout << "B";
	}
	else if (79 >= a&&a >= 70) {
		cout << "C";
	}
	else if (69 >= a&&a >= 60) {
		cout << "D";
	}
	else {
		cout << "F";
	}
	return 0;
}