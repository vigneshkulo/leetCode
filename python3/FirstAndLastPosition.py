class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        
        def binarySearch(start, end, isLeft):
            if (start > end):
                return -1
            
            mid = (start + end) // 2            
            if (target == nums[mid]):
                if isLeft:
                    if (mid > 0) and (nums[mid - 1] < nums[mid]):
                        return mid
                    elif (mid == 0):
                        return mid
                    else:
                        return binarySearch(start, mid - 1, isLeft)
                else:
                    if (mid < (len(nums)-1)) and (nums[mid + 1] > nums[mid]):
                        return mid
                    elif (mid == (len(nums) - 1)):
                        return mid
                    else:
                        return binarySearch(mid + 1, end, isLeft)
            
            if (target < nums[mid]):
                return binarySearch(start, mid - 1, isLeft)
            else:
                return binarySearch(mid + 1, end, isLeft)
        
        output = [-1, -1]
        output[0] = binarySearch(0, len(nums) - 1, True)
        output[1] = binarySearch(0, len(nums) - 1, False)
        
        return output    
