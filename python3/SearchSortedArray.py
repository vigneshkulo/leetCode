class Solution:
    def search(self, nums: List[int], target: int) -> int:
        
        def binarySearch(start, end):
            if (start > end):
                return -1
            
            mid = (start + end) // 2
            
            if (target == nums[mid]):
                return mid
            
            if (target < nums[mid]):
                return binarySearch(start, mid - 1)
            else:
                return binarySearch(mid + 1, end)
        
        pivot = 0
        
        for i in range(1, len(nums)):
            if (nums[i] < nums[i-1]):
                pivot = i
                break
        
        index = binarySearch(0, pivot-1)
        if (index == -1):
            index = binarySearch(pivot, len(nums) - 1)
        
        return index
