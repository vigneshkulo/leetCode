class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        table = [1 for i in range(len(nums))]
        
        for i in range(len(nums)):
            for j in range(i-1, -1, -1):
                if nums[i] > nums[j]:
                    table[i] = max(table[j] + 1, table[i])
        
        for val in table:
            if val == 3:
                return True
        
        return False
