/* Time: O(n), Space O(1) */

class Solution {
public:    
    int minOperations(vector<int>& nums, int x) {
        int start = 0;
        int end = 0;
        int curSum = 0;
        int maxLen = -1;
        int totalSum = 0;
        
        for (auto num : nums) {
            totalSum += num;
        }
        
        totalSum -= x;
        
        if (totalSum == 0) {
            return nums.size();
        }

        while (end < nums.size()) {
            while (start < end && curSum + nums[end] > totalSum) {
                curSum -= nums[start];
                ++start;
            }
            curSum += nums[end];
            if (curSum == totalSum) {
                maxLen = max(maxLen, end - start + 1);
                curSum -= nums[start];
                ++start;
            }
            ++end;            
        }
        
        if (maxLen == -1) {
            return -1;
        }
        
        return nums.size() - maxLen;
    }
};
