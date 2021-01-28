#include<iostream>

int main() {

	int arr[] = { 31, 5, 8, 2, 5, 8, 2, 8, 5, 1, 8, 2 };
	int output = 0;
	int index = 0;

	for (int index = 0; index < sizeof(arr)/sizeof(int); ++index) {
		output ^= (1 << arr[index]);
	}

	if (output < 0) {
		printf("31 ");
		output &= 0x7FFFFFFF;
	}
	while (output) {
		if (output & 1) {
			printf("%d ", index);
		}
		++index;
		output >>= 1;
	}
	return 0;
}
