class Solution:
    def minWindow(self, s: str, t: str) -> str:
        tDict = Counter(t)
        start, end = 0, 0
        
        found = 0
        sDict = {}
        
        minWindow = float("inf")
        wStart = -1
        wEnd = -1
        
        while (end < len(s)):
            if (s[end] in tDict):
                sDict[s[end]] = sDict.get(s[end], 0) + 1
                
                if (sDict[s[end]] == tDict[s[end]]):
                    found += 1

            while (found == len(tDict)):
                if (end - start + 1) < minWindow:
                    minWindow = end - start + 1
                    wStart = start
                    wEnd = end
                
                if s[start] in sDict:
                    sDict[s[start]] -= 1
                    if sDict[s[start]] < tDict[s[start]]:
                        found -= 1
                start += 1
            end += 1
        
        if wStart == -1:
            return ""

        return s[wStart:wEnd+1]
