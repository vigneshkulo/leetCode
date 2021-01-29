#include<iostream>
#include<bitset>

using namespace std;
int main() {

	int val = 215;
	int div = 0;

	/* Multiply by 15 without using multiplication */
	val = (val << 4) - val;
	cout << val << " == " << 215*15 << endl;

	/* Multiple by 7.5 */
	val = 215;
	val = ((val << 4) - val) >> 1;
	cout << val << " == " << 215*7.5 << endl;

	/* Modulo without % */
	val = 215;
	div = 4;
	val = (val & (div - 1));

	cout << val << " == " << 215 % 4 << endl;

	/* Mask generation */
	cout << bitset<32>(~((1 << 29) - 1)) << endl;
	return 0;
}
