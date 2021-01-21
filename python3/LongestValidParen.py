class Solution:
    def longestValidParentheses(self, s: str) -> int:
        dp = [0 for i in range(len(s) + 1)]
        maxWindow = 0
        for i in range(1, len(s)):
            if (s[i] == ')'):
                if (s[i-1] == '('):
                    dp[i+1] = dp[i-1] + 2
                elif (s[i-1] == ')' and ((i - dp[i] - 1) >= 0) and s[i - dp[i] - 1] == '('):
                    dp[i+1] = dp[i] + dp[i - dp[i] - 1] + 2
        
                maxWindow = max(maxWindow, dp[i+1])
        return maxWindow

