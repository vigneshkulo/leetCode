class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        
        if (grid[0][0] == 1):
            return -1
        
        queue = [(0, 0)]
        curLevel = 0
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1], [-1, -1], [1, 1], [-1, 1], [1, -1]]
        
        def addItem(row, col):
            if (row < 0 or row >= len(grid) or col < 0 or col >= len(grid[0]) or grid[row][col] == 1):
                return
            
            queue.append((row, col))
            return
            
        while (len(queue) != 0):
            curLen = len(queue)
            curLevel += 1
            for i in range(curLen):
                curRow, curCol = queue.pop(0)
                if (grid[curRow][curCol] == 1):
                    continue

                grid[curRow][curCol] = 1
                
                if ((curRow == (len(grid) - 1)) and (curCol == (len(grid[0]) - 1))):
                    return curLevel
                
                for direc in directions:
                    addItem(curRow + direc[0], curCol + direc[1])
        
        return -1
