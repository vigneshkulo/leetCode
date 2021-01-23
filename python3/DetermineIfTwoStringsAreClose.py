class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if (len(word1) != len(word2)):
            return False
        
        unique1 = [0 for i in range(26)]
        unique2 = [0 for i in range(26)]
        
        for char in word1:
            unique1[ord(char) - ord('a')] += 1
        
        for char in word2:
            index = ord(char) - ord('a')
            if unique1[index] == 0:
                return False
            
            unique2[index] += 1
        
        unique1.sort()
        unique2.sort()
        
        return unique1 == unique2
