class Solution:
    def partition(self, s: str) -> List[List[str]]:
        
        self.output = []
        def isPalindrome(start, end):
            while (end > start):
                if (s[end] != s[start]):
                    return False
                end -= 1
                start += 1
            return True
            
        def findPartition(curIndex, curList):
            if (curIndex == len(s)):
                self.output.append(list(curList))
                return
            
            for i in range(curIndex, len(s)):
                subString = s[curIndex:i+1]
                if isPalindrome(curIndex, i):
                    curList.append(subString)
                    findPartition(curIndex + len(subString), curList)
                    curList.pop()
            return

        findPartition(0, [])
        
        return self.output
