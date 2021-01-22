class Solution:
    def mostCompetitive(self, nums: List[int], k: int) -> List[int]:
        output = [float("inf")]
        
        for index, num in enumerate(nums):
            curLen = len(output)
            numsLeft = len(nums) - index - 1
            
            while ( len(output) and (num < output[-1]) and (numsLeft >= (k - len(output))) ):
                output.pop()
            
            if len(output) < k:
                output.append(num)
            
        return output
