# Runtime: 175 ms (Top 99.44%) | Memory: 16.6 MB (Top 61.84%)
class Solution:
    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        m, n = len(board), len(board[0])
        x, y = click

        def dfs(x, y):
            mines = 0
            # Return if we are out of range on the board or if the space is already filled
            if x < 0 or x >= m or y < 0 or y >= n or board[x][y] != "E":
                return

            # Search for mines in any direction at your current location, increment mine count if one is found
            for newX, newY in [(1,0), (-1,0), (0,1), (0,-1), (1,1), (1,-1), (-1,1), (-1,-1)]:
                if 0 <= x+newX < m and 0 <= y+newY < n and board[x+newX][y+newY] == "M":
                    mines += 1

            # If no mines found, then it is a blank space
            if mines == 0:
                board[x][y] = "B"
            # If mines are found them put the count on the board, then return as we don't need to search past this location on the board
            else:
                board[x][y] = str(mines)
                return

            # Recurse through other board locations
            for newX, newY in [(1,0), (-1,0), (0,1), (0,-1), (1,1), (1,-1), (-1,1), (-1,-1)]:
                dfs(x+newX, y+newY)

            return

        # If you clicked on a bomb, game over immediately
        if board[x][y] == "M":
            board[x][y] = "X"
        # Else game on!
        else:
            dfs(x, y)
        return board