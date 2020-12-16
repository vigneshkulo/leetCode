class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        
        def isMine(row, col):
            if (row < 0) or (row >= len(board)) or (col < 0) or (col >= len(board[0])):
                return 0
            
            if (board[row][col] == 'M'):
                return 1
            
            return 0
            
        def dfs(row, col):
            if (row < 0) or (row >= len(board)) or (col < 0) or (col >= len(board[0])):
                return
            
            if (board[row][col] != 'E'):
                return
            
            # Blank
            mine = 0
            mine += isMine(row, col - 1)
            mine += isMine(row, col + 1)

            mine += isMine(row + 1, col)
            mine += isMine(row - 1, col)
            
            mine += isMine(row - 1, col - 1)
            mine += isMine(row + 1, col - 1)
            mine += isMine(row - 1, col + 1)
            mine += isMine(row + 1, col + 1)
            
            if (mine > 0):
                board[row][col] = str(mine)
            else:
                board[row][col] = 'B'
                dfs(row, col - 1)
                dfs(row, col + 1)
                dfs(row + 1, col)
                dfs(row - 1, col)

                dfs(row + 1, col - 1)
                dfs(row + 1, col + 1)
                dfs(row - 1, col - 1)
                dfs(row - 1, col + 1)
            
            return
            
        # BOOM
        if (board[click[0]][click[1]] == 'M'):
            board[click[0]][click[1]] = 'X'
            return board
        
        dfs(click[0], click[1])
        return board
