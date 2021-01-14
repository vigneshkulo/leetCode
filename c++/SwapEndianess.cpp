#include <iostream>

using namespace std;

int main() {

	int x = 0x12345678;

	char* start = (char*)&x;
	char* end = start + 3;

	while (end > start) {
		*start ^= *end;
		*end ^= * start;
		*start ^= *end;

		++start;
		--end;
	}

	printf("* %x\n", x);
	return 0;
}
