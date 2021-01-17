class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        alienDict = {}
        index = 0
        for char in order:
            alienDict[char] = index
            index += 1
        
        def checkOrder(left, right):
            lindex = 0
            rindex = 0
            while (lindex < len(left) and rindex < len(right) and left[lindex] == right[rindex]):
                lindex += 1
                rindex += 1
            
            if (lindex < len(left) and rindex < len(right) and alienDict[left[lindex]] > alienDict[right[rindex]]):
                return False
            
            if (lindex < len(left) and rindex >= len(right)):
                return False
            
            return True
        
        for i in range(1, len(words)):
            if not(checkOrder(words[i-1], words[i])):
                return False
        
        return True

