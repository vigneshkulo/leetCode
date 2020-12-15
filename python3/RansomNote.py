class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        memo = {}
        
        for char in magazine:
            if char in memo:
                memo[char] += 1
            else:
                memo[char] = 1
        
        for char in ransomNote:
            if char not in memo:
                return False
            else:
                if memo[char] <= 0:
                    return False
                memo[char] -= 1
        
        return True
