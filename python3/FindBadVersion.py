class Solution:
    def firstBadVersion(self, n):
        
        def binarySearch(start, end):
            if (start > end):
                return -1
            
            mid = (start + end) // 2
            
            if (isBadVersion(mid)):
                if (mid == start):
                    return mid
                
                left = binarySearch(start, mid-1)
                return left if left != -1 else mid
            else:
                return binarySearch(mid+1, end)
        
        return binarySearch(1, n)
