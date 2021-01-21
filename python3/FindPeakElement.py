class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        
        def binarySearch(start, end):
            if (start > end):
                return -1
            
            mid = (start + end) // 2
            
            left = float("-inf")
            right = float("-inf")
            
            if mid > 0:
                left = nums[mid-1]
            if mid < (len(nums) - 1):
                right = nums[mid+1]

            if (left < nums[mid] and nums[mid] > right):
                return mid
            
            output = binarySearch(start, mid - 1)
            if (output == -1):
                output = binarySearch(mid + 1, end)
            
            return output
            
        return binarySearch(0, len(nums) - 1)
