# Time: O(n), Space: O(1)

class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:

        missing = 0
        index = 0
        
        for val in range(1, arr[-1]+1):
            if val == arr[index]:
                index += 1
            else:
                missing += 1
            
            if (missing == k):
                return val
        
        return arr[-1] + k - missing
