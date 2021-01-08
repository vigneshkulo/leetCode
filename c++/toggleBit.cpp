#include <iostream>

int main() { 

	int k = 4;
	int val = 213;

	printf("* %d -> Toggle %d bit = %d\n", val, k, val ^ (1 << k-1));
	return 0;
}
