class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        def swap(index1, index2):
            temp = nums[index1]
            nums[index1] = nums[index2]
            nums[index2] = temp
            return
        
        endIndex = len(nums) - 1
        curIndex = endIndex
        while (curIndex > 0):
            if (nums[curIndex] > nums[curIndex - 1]):
                break
            curIndex -= 1
        
        startIndex = curIndex - 1
        if (curIndex != 0):
            startIndex = curIndex - 1
            curIndex += 1
            while (curIndex <= endIndex and nums[curIndex] > nums[startIndex]):
                curIndex += 1

            curIndex -= 1
            swap(startIndex, curIndex)
        
        curIndex = startIndex + 1
        while (endIndex > curIndex):
            swap(curIndex, endIndex)
            endIndex -= 1
            curIndex += 1
            
        return
