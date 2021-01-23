class Solution:
    def isOneEditDistance(self, s: str, t: str) -> bool:
        if abs(len(s) - len(t)) > 1:
            return False
        
        self.isChanged = False
        def dfs(curIndex, tIndex):
            if (curIndex >= len(s)) or (tIndex >= len(t)):
                if not (self.isChanged) and (len(s) != len(t)):
                    return True
                elif (self.isChanged) and (curIndex == len(s)) and (tIndex == len(t)):
                    return True
                else:
                    return False
            
            if (s[curIndex] == t[tIndex]):
                return dfs(curIndex + 1, tIndex + 1)
            
            ret = False
            if not (self.isChanged):
                self.isChanged = True
                if (len(s) < len(t)):
                    ret = dfs(curIndex, tIndex + 1)
                    if ret:
                        return ret
                
                if (len(s) > len(t)):
                    ret = dfs(curIndex + 1, tIndex)
                    if ret:
                        return ret
                
                if (len(s) == len(t)):
                    ret = dfs(curIndex + 1, tIndex + 1)
            return ret
        
        return dfs(0, 0)
