#include <iostream>
#include <cstring>

int main () {

	char str[20];
	int output = 0;
	bool isNeg = false;
	strncpy(str, "098993489", 20);
	char* cur = str;

	if (*cur == '-') {
		isNeg = true;
		cur++;
	}

	while (*cur != '\0') {
		if (*cur >= '0' && *cur <= '9') {
			output *= 10;
			output += (*cur - '0');
			cur++;
		} else {
			output = 0;
			break;
		}
	}

	if (isNeg) {
		output *= -1;
	}

	printf("%s -> %d\n", str, output);
	return 0;
}
