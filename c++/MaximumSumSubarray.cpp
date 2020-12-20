class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int curMax = nums[0];
        int globalMax = curMax;
        
        for (int inx = 1; inx < nums.size(); ++inx) {
            curMax = max(nums[inx], curMax + nums[inx]);
            globalMax = max(globalMax, curMax);
        }
        
        return globalMax;
    }
};
