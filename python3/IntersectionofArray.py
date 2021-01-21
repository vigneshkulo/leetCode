class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        seen = {}
        
        for item in nums1:
            if item not in seen:
                seen[item] = 1
        
        output = set()
        
        for item in nums2:
            if item in seen:
                output.add(item)
        
        return list(output)
