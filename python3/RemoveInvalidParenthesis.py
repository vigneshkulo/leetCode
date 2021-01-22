class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        if s == "":
            return [""]
        
        output = set()
        maxLen = 0        
        numOpen = 0
        numClose = 0
        
        for index, char in enumerate(s):
            if char == ')':
                if numOpen > 0:
                    numOpen -= 1
                else:
                    numClose += 1
            elif char == '(':
                numOpen += 1

        def dfs(openCount, closeCount, skipOpen, skipClose, curIndex, curString):
            if (curIndex >= len(s)):
                if (openCount == closeCount):
                    output.add(curString)
                return
            
            if (s[curIndex] == '('):
                if (skipOpen > 0):
                    dfs(openCount, closeCount, skipOpen-1, skipClose, curIndex + 1, curString)
                dfs(openCount + 1, closeCount, skipOpen, skipClose, curIndex + 1, curString + s[curIndex])
            elif (s[curIndex] == ')'):
                if (skipClose > 0):
                    dfs(openCount, closeCount, skipOpen, skipClose-1, curIndex + 1,  curString)
                if (openCount > closeCount):
                    dfs(openCount, closeCount + 1, skipOpen, skipClose, curIndex + 1, curString + s[curIndex])
            else:
                dfs(openCount, closeCount, skipOpen, skipClose, curIndex + 1, curString + s[curIndex])
            
            return

        dfs(0, 0, numOpen, numClose, 0, "")
        
        return output
