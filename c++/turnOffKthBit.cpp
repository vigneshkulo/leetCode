#include <iostream>

int main() { 

	int k = 5;
	int val = 213;

	printf("* %d -> Turn off %d bit = %d\n", val, k, val & ~(1 << k-1));
	return 0;
}
