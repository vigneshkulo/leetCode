class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        
        output = [0 for i in range(len(nums))]
        start = 0
        end = len(nums) - 1
        
        while (end >= start):
            left, right = abs(nums[start]), abs(nums[end])
            if left > right:
                output[end-start] = left * left
                start += 1
            else:
                output[end-start] = right * right
                end -= 1

        return output
