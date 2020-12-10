#include <iostream>
#include <vector>
#include <unordered_map>
#include "Helper.h" 

using namespace std;

class TwoSum {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int diff = 0;
		unordered_map <int, int> seen;
		vector<int> output = {-1, -1};

		for (int index = 0; index < nums.size(); ++index) {
			diff = target - nums[index];
			cout << diff << endl;
			if (seen.find(diff) != seen.end()) {
				output[0] = seen[diff];
				output[1] = index;
				break;
			} else {
				seen[nums[index]] = index;
			}
		}
		
		return output;
	}
};

int main() {

	TwoSum sol;
	vector<int> input = {2,7,11,15};
	vector<int> output = sol.twoSum(input, 9);

	return 0;
}
