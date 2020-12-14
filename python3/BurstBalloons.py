class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        if (nums == []):
            return 0
        
        dp = [[0 for j in range(len(nums))] for i in range(len(nums))]
        for win in range(1, len(nums)+1):
            right = win - 1
            while (right < len(nums)):
                left = right - win + 1
                for k in range(left, right+1):
                    l, r = 1, 1
                    dpleft, dpright = 0, 0
                    if (left != 0):
                        l = nums[left - 1]
                    
                    if (right != len(nums)-1):
                        r = nums[right + 1]
                    

                    if k-1 >= left:
                        dpleft = dp[left][k-1]
                    
                    if k+1 <= right:
                        dpright = dp[k+1][right]
                        
                    dp[left][right] = max(dp[left][right], dpleft + (l * nums[k] * r) + dpright)
                    
                right += 1
        
        return dp[0][-1]
