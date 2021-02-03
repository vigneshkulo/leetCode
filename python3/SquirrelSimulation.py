class Solution:
    def minDistance(self, height: int, width: int, tree: List[int], squirrel: List[int], nuts: List[List[int]]) -> int:
    
        def distance(a, b):
            return abs(a[0] - b[0]) + abs(a[1] - b[1])
        
        shortestPath = 0
        firstIndex = -1
        maxSaving = float("-inf")
        for index, nut in enumerate(nuts):
            nut2tree = distance(nut, tree)
            nut2squi = distance(nut, squirrel)
            if (nut2tree - nut2squi) > maxSaving:
                maxSaving = nut2tree - nut2squi
                firstIndex = index
        
        shortestPath += distance(squirrel, nuts[firstIndex])        
        shortestPath += distance(nuts[firstIndex], tree)
        
        for index, nut in enumerate(nuts):
            if (index != firstIndex):
                shortestPath += (distance(nut, tree) * 2)
                
        return shortestPath
