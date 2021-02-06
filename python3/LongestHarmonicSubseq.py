class Solution:
    def findLHS(self, nums: List[int]) -> int:
        seen = {}
        longest = 0
        for val in nums:
            seen[val] = seen.get(val, 0) + 1
        
        for key in seen:           
            if key + 1 in seen:
                longest = max(longest, seen[key] + seen[key + 1])

        return longest
