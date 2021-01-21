class Solution:
    def numDecodings(self, s: str) -> int:
        if (len(s) == ""):
            return 0

        dp = [0 for i in range(len(s) + 1)]
        dp[0] = 1
        if (s[0] != '0'):
            dp[1] = 1
        
        for i in range(1, len(s)):
            if (s[i] != '0'):
                dp[i+1] += dp[i]
            else:
                dp[i+1] = 0
            
            if (s[i-1] != '0'):
                couple = s[i-1] + s[i]
                if (int(couple) > 0 and int(couple) <= 26):
                    dp[i+1] += dp[i-1]
        
        return dp[-1]
