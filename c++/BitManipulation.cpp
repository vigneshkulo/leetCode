#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isPowerof2(unsigned int num) {
	return !(num & (num - 1));
}

int getRightMostSetBit(int num) {
	num ^= num - 1;

	int k = 0;
	while (num) {
		num >>= 1;
		++k;
	}

	return k;
}

int getNumBits(int num) {

	int count = 0;

	while (num) {
		++count;
		num &= (num - 1);
	}

	return count;
}

int getLeftMostBit(int num) {
	int k = 0;
	int prev = num;

	while (num) {
		prev = num;
		num &= (num - 1);
	}

	while (prev) {
		++k;
		prev >>= 1;
	}

	return k;
}

int roundup(int num) {
	if (!(num & (num - 1))) {
		return num;
	}

	int prev = 0;
	while (num) {
		prev = num;
		num &= (num - 1);
	}

	return prev << 1;
}

int roundlower(int num) {
	if (!(num & (num - 1))) {
		return num;
	}

	int prev = 0;
	while (num) {
		prev = num;
		num &= (num - 1);
	}

	return prev;
}

int reverseBits(int num) {
	int reversed = 0;

	for (int i = 0; i < 32; ++i) {
		reversed |= (num & 0x1);
		reversed <<= 1;
		num >>= 1;
	}

	return reversed;
}

int swapBits(int num, int pos1, int pos2) {
	int swapped = num;

	if((1 << pos1) & num) {
		swapped |= (1 << pos2);
	} else {
		swapped &= ~(1 << pos2);
	}

	if((1 << pos2) & num) {
		swapped |= (1 << pos1);
	} else {
		swapped &= ~(1 << pos1);
	}

	return swapped;
}

int swapAdjBits(int num) {

	int pos1 = 0;
	int pos2 = 1;

	int output = num;
	for (int i = 0; i < 16; ++i) {
		if ( (((1 << pos1) & num) >> pos1) ^ (((1 << pos2) & num) >> pos2) ) {
			output ^= (1 << pos1); 
			output ^= (1 << pos2); 
		}
		pos1 += 2;
		pos2 += 2;
	}

	return output;
}

int main() {

	unsigned int val1 = 20;
	unsigned int val2 = 1024;
	
	/* Check if power of 2 */
	cout << val1 << (isPowerof2(val1) ? " is " : " is not ") << "power of 2" << endl;
	cout << val2 << (isPowerof2(val2) ? " is " : " is not ") << "power of 2" << endl;
	cout << endl;

	/* Get rightmost set bit */
	cout << "Rightmost set bit in " << val1 << " is " << getRightMostSetBit(val1) << endl;
	cout << "Rightmost set bit in " << val2 << " is " << getRightMostSetBit(val2) << endl;
	cout << endl;

	/* Count set bits */
	cout << "Number of bits set in " << val1 << " is " << getNumBits(val1) << endl;
	cout << "Number of bits set in " << val2 << " is " << getNumBits(val2) << endl;
	cout << endl;

	/* Find leftmost bit */
	cout << "Leftmost set bit is " << getLeftMostBit(val1) << endl;
	cout << "Leftmost set bit is " << getLeftMostBit(val2) << endl;
	cout << endl;

	/* Round up to next highest power of 2 */
	cout << "Next highest power of " << val1 << " is " << roundup(val1) << endl;
	cout << "Next highest power of " << val2 << " is " << roundup(val2) << endl;
	cout << endl;

	/* Round down to next highest power of 2 */
	cout << "Next lowest power of " << val1 << " is " << roundlower(val1) << endl;
	cout << "Next lowest power of " << val2 << " is " << roundlower(val2) << endl;
	cout << endl;

	/* Reverse Bits */
	cout << "Reverse Bits: " << bitset<32>(val1) << " " << bitset<32>(reverseBits(val1)) << endl;
	cout << "Reverse Bits: " << bitset<32>(val2) << " " << bitset<32>(reverseBits(val2)) << endl;
	cout << endl;

	/* Swap bits */
	cout << "Swap Bits 2 and 6: " << bitset<32>(31) << " " << bitset<32>(swapBits(31, 2, 6)) << endl;
	cout << "Swap Bits 1 and 5: " << bitset<32>(47) << " " << bitset<32>(swapBits(47, 1, 5)) << endl;
	cout << endl;

	/* Swap adjacent bits */
	cout << "Swap adjacent bits: " << endl;
	cout << bitset<32>(761622921) << endl;
	cout << bitset<32>(swapAdjBits(761622921)) << endl;
	return 0;
}
