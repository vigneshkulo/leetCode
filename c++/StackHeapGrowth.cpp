#include <iostream>

using namespace std;

int main() {

	int a = 0;
	int b;

	if (&a > &b) {
		cout << "Stack grows down" << endl;
	} else {
		cout << "Stack grows up" << endl;
	}

	return 0;
}
