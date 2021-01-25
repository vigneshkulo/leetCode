class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        self.output = []

        def dfs(curIndex):
            if curIndex == len(nums):
                self.output.append(nums.copy())
                return
            
            lookup = set()
            for i in range(curIndex, len(nums)):
                if (nums[i] not in lookup):
                    temp = nums[i]
                    nums[i] = nums[curIndex]
                    nums[curIndex] = temp
                    
                    dfs(curIndex + 1)
                    
                    temp = nums[i]
                    nums[i] = nums[curIndex]
                    nums[curIndex] = temp
                    
                    lookup.add(nums[i])
            return
        
        dfs(0)
        
        return self.output
                    
