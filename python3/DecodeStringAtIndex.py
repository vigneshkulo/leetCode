class Solution:
    def decodeAtIndex(self, S: str, K: int) -> str:
        stack = []
        
        curLen = 0
        curStart = -1
        prevLen = 0

        for index, char in enumerate(S):
            if char.isdigit():
                curLen *= int(char)

                if (curStart != -1):
                    mod = index - curStart + prevLen
                    stack.append([curStart, prevLen, mod])
                curStart = -1
                prevLen = curLen
            else:
                curLen += 1
                if curStart == -1:
                    curStart = index
                
            if K <= curLen:
                if (curStart != -1):
                    return char             
                break
        
        index = K - 1
        while(stack != []):
            strInx, start, mod = stack[-1]
            index = index % mod
            
            if (index >= start):
                return S[strInx + (index - start)]
            
            stack.pop()
