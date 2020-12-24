class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        
        memo = {"]" : "[", ")" : "(", "}" : "{"}
        for char in s:
            if char in "({[":
                stack.append(char)
            else:
                if len(stack) > 0 and memo[char] == stack[-1]:
                    stack.pop()
                else:
                    return False
        
        return len(stack) == 0
