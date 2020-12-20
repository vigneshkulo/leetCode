class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        minSeen = float("inf")
        maxSeen = float("-inf")
        seqLen = 0
        
        for num in nums:
            if num > maxSeen:
                seqLen += 1
            if minSeen < num < maxSeen:
                maxSeen = num
            
            if (minSeen != maxSeen) and (maxSeen == num) and (seqLen == 1):
                seqLen += 1
                
            if seqLen == 3:
                return True
            
            minSeen = min(minSeen, num)
            maxSeen = max(maxSeen, num)
        
        return False
