#include <iostream>
#include <vector>

using namespace std;
class Solution {
	public:
		bool validMountainArray(vector<int> &arr) {
			if (arr.size() < 3) {
			    return false;
			}
			
			bool increasing = true;
			if (arr[0] >= arr[1]) {
			    return false;
			}
			
			for (int curIndex = 1; curIndex < arr.size(); ++curIndex) {
			    if (arr[curIndex] == arr[curIndex-1]) {
				return false;
			    }
			    
			    if (arr[curIndex] < arr[curIndex-1]) {
				if (increasing)
				    increasing = false;
			    } else {
				if (!increasing)
				    return false;
			    }
			}
			
			return (increasing == false);			
		}
};

int main() {
	Solution sol;
//	vector<int> inputArray = {1,2,3,2,1};
//	vector<int> inputArray = {1,2,2,3,2,1};
//	vector<int> inputArray = {5,4,3,2,1};
	vector<int> inputArray = {1,2,3,4,5};

	printf("%s\n", sol.validMountainArray(inputArray) ? "true" : "false");

	return 0;
}
