#include <iostream>

int main() { 

	int k = 4;
	int val = 213;

	printf("* %d bit is %s\n", k, val & (1 << k-1) ? "Set" : "Not Set");
	return 0;
}
