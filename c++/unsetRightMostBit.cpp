#include <iostream>

int main() {
	int val = 1320;

	printf("* %d -> unset rightmost bit: %d\n", val, val & (val-1));
	return 0;
}
