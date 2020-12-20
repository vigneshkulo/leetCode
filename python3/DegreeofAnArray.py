class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        degree = 1
        winMap = {}
        
        for index, val in enumerate(nums):
            if val in winMap:
                winMap[val][0] += 1
                winMap[val][2] = index
                degree = max(degree, winMap[val][0])
            else:
                winMap[val] = [1, index, index]
        
        minWin = float("inf")
        for key in winMap:
            if winMap[key][0] == degree:
                minWin = min(minWin, winMap[key][2] - winMap[key][1] + 1)
        
        return minWin
