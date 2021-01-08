# Time: O(n), Space: O(n)

class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        found = {}
        
        for item in arr:
            found[item] = True
        
        curItem = 1
        while (k):
            if curItem not in found:
                k -= 1
            curItem += 1
        
        return curItem -1 
