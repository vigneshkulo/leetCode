class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        
        numIslands = 0
        def dfs(row, col):
            if (row < 0) or (row >= len(grid)) or (col < 0) or (col >= len(grid[0])):
                return
            
            if (grid[row][col] != "1"):
                return
            
            grid[row][col] = "2"
            
            dfs(row, col - 1)
            dfs(row, col + 1)
            dfs(row + 1, col)
            dfs(row - 1, col)
        
        for row in range(len(grid)):
            for col in range(len(grid[0])):
                if (grid[row][col] == "1"):
                    dfs(row, col)
                    numIslands += 1
        
        return numIslands
