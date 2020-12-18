class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        total = [[0 for j in range(len(pizza[0]) + 1)] for i in range(len(pizza) + 1)]
        totalApples = 0
        
        for i in range(1, len(pizza)+1):
            for j in range(1, len(pizza[0])+1):
                if (pizza[i-1][j-1] == 'A'):
                    total [i][j] = 1
                    totalApples += 1

                total[i][j] += total[i-1][j]
                total[i][j] += total[i][j-1]
                total[i][j] -= total[i-1][j-1]
        
        def getShare(row, col):
            row += 1
            col += 1
            return total[-1][-1] - total[-1][col-1] - total[row-1][-1] + total[row-1][col-1]
        
        modulo = (10 ** 9) + 7
        
        @lru_cache(None)
        def dfs(rowStart, colStart, curCuts, curApples):
            if (curCuts == k-1):
                return 1
            
            ways = 0
            # Horizontal cuts
            for rcut in range(rowStart, len(pizza)-1):
                lower = getShare(rcut+1, colStart)
                if (lower > 0) and (curApples - lower > 0):
                    ways += dfs(rcut + 1, colStart, curCuts+1, lower)

            # Vertical cuts
            for ccut in range(colStart, len(pizza[0])-1):
                right = getShare(rowStart, ccut+1)
                if (right > 0) and (curApples - right > 0):
                    ways += dfs(rowStart, ccut + 1, curCuts+1, right)
            
            return ways % (modulo)
        
        return dfs(0, 0, 0, totalApples)
