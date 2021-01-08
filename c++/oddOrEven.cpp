#include <iostream>

int main() {

	int val = 5;
	val = 2144;

	if (val & 0x1) {
		printf("* Odd\n");
	} else {
		printf("* Even\n");
	}

	return 0;
}
