/* Time: Exponential, memoization helps */

class Solution {
public:
    unordered_map<string, int> map;
    int getMin(int start, int end, int val, vector<int>& nums) {        
        if (val == 0) {
            return 0;
        }

        if (end < start || val < 0) {
            return -1;
        }
        
        string key = to_string(start) + to_string(end) + to_string(val);
        if (map.find(key) != map.end()) {
            return map[key];
        }
        
        int left = getMin(start+1, end, val - nums[start], nums);
        int right = getMin(start, end-1, val - nums[end], nums);
        
        map[key] = -1;
        if (left != -1 && right != -1) {
            map[key] = min(left, right) + 1;
        } else if (left != -1) {
            map[key] = left + 1;
        } else if (right != -1) {
            map[key] = right + 1;
        }
        
        return map[key];
    }
    
    int minOperations(vector<int>& nums, int x) {
        return getMin(0, nums.size()-1, x, nums);
    }
};
