#include <iostream>

int main() {

	int val1 = 10;
	int val2 = -5;

	val1 = 10;
	val2 = 5;

	val1 = -10;
	val2 = -5;

	val1 = -10;
	val2 = 5;

	if ((val1 ^ val2) < 0) {
		printf("* Opposite sign\n");
	} else {
		printf("* Same sign\n");
	}
	return 0;
}
