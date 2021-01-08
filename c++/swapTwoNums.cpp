#include <iostream>

int main() {

	int val1 = 10;
	int val2 = 20;

	val1 = -100;
	val2 = -20;

	printf("* Before: %d and %d\n", val1, val2);

	val1 ^= val2;
	val2 ^= val1;
	val1 ^= val2;

	printf("* After: %d and %d\n", val1, val2);
	return 0;
}
