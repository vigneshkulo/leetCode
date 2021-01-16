class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        memo = {}
        def getMin(start, end, val):
            if (val == 0):
                return 0
            
            if (end < start or val < 0):
                return -1
            
            key = str(start) + str(end) + str(val)
            if key in memo:
                return memo[key]
            
            print(start, end, val)
            left = getMin(start+1, end, val - nums[start])
            right = getMin(start, end-1, val - nums[end])
            
            output = -1
            if (left != -1 and right != -1):
                output = min(left, right) + 1
            elif (left != -1):
                output = left + 1
            elif (right != -1):
                output = right + 1
            
            memo[key] = output
            return output

        return getMin(0, len(nums)-1, x)
