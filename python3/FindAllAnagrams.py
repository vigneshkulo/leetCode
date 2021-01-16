class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        pHash = [0] * 26
        
        for char in p:           
            pHash[ord(char) - ord('a')] += 1
                
        curStart = 0
        curIndex = 0
        output = []
        curHash = [0] * 26
        
        while (curIndex < len(s)):
            curHash[ord(s[curIndex]) - ord('a')] += 1
            curIndex += 1      
            if (curIndex - curStart) == len(p):
                if (curHash == pHash):
                    output.append(curStart)
                
                curHash[ord(s[curStart]) - ord('a')] -= 1
                curStart += 1
                
        return output
