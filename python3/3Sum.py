class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        nums.sort()
        output = []
        
        def twoSum(left, right, target):
            twoSums = []
            while (right > left):
                curSum = nums[left] + nums[right]
                if curSum == target:
                    twoSums.append([nums[left], nums[right]])
                    left += 1
                    right -= 1
                    while (right > left and nums[left] == nums[left - 1]):
                        left += 1
                elif curSum < target:
                    left += 1
                else:
                    right -= 1
            
            return twoSums
        
        prev = float("inf")
        for index in range(len(nums) - 2):
            if (nums[index] > 0):
                break
            if (nums[index] != prev):
                prev = nums[index]
                twosums = twoSum(index + 1, len(nums) - 1, -nums[index])
                if len(twosums):
                    for item in twosums:
                        output.append([nums[index]] + item)
        
        return output
