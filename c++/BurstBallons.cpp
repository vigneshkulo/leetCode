class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int len = nums.size();
        if (len == 0)
            return 0;
        
        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        for (int win = 1; win <= len; ++win) {
            int right = win - 1;
            for (int right = win - 1; right < len; ++right) {
                int left = right - win + 1;
                for (int k = left; k <= right; ++k) {
                    int l = 1, r = 1;
                    int dpleft = 0, dpright = 0;
                    
                    if (left != 0)
                        l = nums[left - 1];
                    
                    if (right != len-1)
                        r = nums[right + 1];
                    
                    if (k-1 >= left)
                        dpleft = dp[left][k-1];
                    
                    if (k+1 <= right)
                        dpright = dp[k+1][right];
                        
                    dp[left][right] = max(dp[left][right], (dpleft + (l * nums[k] * r) + dpright));
                }
            }
        }
        return dp[0][len-1];
    }
};
