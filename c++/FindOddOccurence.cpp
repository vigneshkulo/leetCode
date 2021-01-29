#include <iostream>

using namespace std;

int binarySearch(int start, int end, int *arr) {
	if (start > end) {
		return -1;
	}

	int mid = (start + end) / 2;
	if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid+1]) {
		return arr[mid];
	}

	if (arr[mid] == arr[mid - 1] && arr[mid] == arr[mid+1]) {
		return arr[mid];
	}

	int ret = binarySearch(start, mid - 1, arr);
	if (ret == -1) {
		ret = binarySearch(mid + 1, end, arr);
	}

	return ret;
}

int main() {

//	int arr[] = {2,2,3,3,2,2,4,4,3,1,1};
	int arr[] = {1,1,2,2,2,3,3};

	int totalLen = (sizeof(arr)/sizeof(int));
	int output = -1;

	if (arr[0] != arr[1]) {
		output = arr[0];
	} else if (arr[totalLen-1] != arr[totalLen-2]) {
		output = arr[totalLen-1];
	}

	output = binarySearch(1, (sizeof(arr)/sizeof(int)) - 2, arr);

	cout << output << endl;
	return output;
}
