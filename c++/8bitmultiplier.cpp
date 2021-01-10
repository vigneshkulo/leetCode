#include <iostream>

using namespace std;

unsigned short multi_8bit(unsigned char a, unsigned char b) {
	return a*b;
}

int main () {

	unsigned int output = 0;

	unsigned int val1 = 1024;
	unsigned int val2 = 4546;

	unsigned char low1 = val1 & 0xFF;
	unsigned char high1 = (val1 & 0xFF00) >> 8;
	unsigned char low2 = val2 & 0xFF;
	unsigned char high2 = (val2 & 0xFF00) >> 8;

	unsigned short low_low = multi_8bit(low1, low2);
	unsigned short low_high = multi_8bit(low1, high2);
	unsigned short high_low = multi_8bit(high1, low2);
	unsigned short high_high = multi_8bit(high1, high2);

	output = low_low + ((low_high + high_low) << 8) + (high_high << 16);

	cout << output << " vs "<< val1 * val2 << endl;
	return 0;
}
