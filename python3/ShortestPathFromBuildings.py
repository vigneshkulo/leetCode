class Solution:
    def shortestDistance(self, grid: List[List[int]]) -> int:
        
        self.minLen = float("inf")
        self.totalBuildings = 0       
        self.reach = [[0 for col in range(len(grid[0]))] for row in range(len(grid))]
        self.dist = [[0 for col in range(len(grid[0]))] for row in range(len(grid))]
        self.directions = [[0,1], [0,-1], [1,0], [-1,0]]
        
        def isValid(currow, curcol, visited):
            if (currow < 0 or currow >= len(grid) or curcol < 0 or curcol >= len(grid[0])):
                return False
            if (visited[currow][curcol] == 1):
                return False
            if (grid[currow][curcol] != 0):
                return False
            
            return True

        
        def bfs(row, col):
            if (row < 0 or row >= len(grid) or col < 0 or col >= len(grid[0])):
                return
            
            queue = [(row, col)]
            found = 0
            curLevel = 0
            curTotal = 0
            visited = [[0 for col in range(len(grid[0]))] for row in range(len(grid))]
            
            while (len(queue)):
                curLen = len(queue)
                for i in range(curLen):
                    currow, curcol = queue.pop(0)
                    if (visited[currow][curcol] == 1):
                        continue
                        
                    for direc in self.directions:
                        if (isValid(currow + direc[0], curcol + direc[1], visited)):
                            queue.append((currow + direc[0], curcol + direc[1]))

                    visited[currow][curcol] = 1                            
                    if (grid[currow][curcol] == 0):
                            self.reach[currow][curcol] += 1
                            self.dist[currow][curcol] += curLevel
                
                curLevel += 1
            return
        
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if (grid[row][col] == 1):
                    bfs(row, col)
                    self.totalBuildings += 1

        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if (self.reach[row][col] == self.totalBuildings):
                    self.minLen = min (self.minLen, self.dist[row][col])
        
        return self.minLen if self.minLen != float("inf") else -1
