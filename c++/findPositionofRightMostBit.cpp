#include<iostream>

int main() {

	int val = 1320;
	int k = 0;

	val ^= (val - 1);
	while (val) {
		k++;
		val >>= 1;
	}

	printf("* Rightmost bit is %d bit\n", k);
	return 0;
}
