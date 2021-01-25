class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        
        keypad = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        self.output = []
       
        def dfs(curIndex, curString):
            if (curIndex == len(digits)):
                if len(curString):
                    self.output.append("".join(char for char in curString))
                return
            
            for char in keypad[int(digits[curIndex])]:
                curString.append(char)
                dfs(curIndex + 1, curString)
                curString.pop()
            return
        
        dfs(0, [])
        
        return self.output
