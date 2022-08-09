class Solution:
    def placeWordInCrossword(self, board: List[List[str]], word: str) -> bool:
        m, n = len(board), len(board[0])
        W = len(word)
        
        def valid(x, y):
            return 0 <= x < m and 0 <= y < n
        
        def place(x, y, word, direction):
            dx, dy = direction
            for c in word:
                if not valid(x, y) or board[x][y] == '#' or (board[x][y] != ' ' and board[x][y] != c):
                    return False
                x, y = x+dx, y+dy
            return True
            
        
        for x in range(m):
            for y in range(n):
                if board[x][y] == '#' or (board[x][y] != ' ' and board[x][y] != word[0]):
                    continue
                
                # left to right
                if (not valid(x, y-1) or board[x][y-1] == '#') and (not valid(x, y+W) or board[x][y+W] == '#') and place(x, y, word, [0, 1]):
                    return True
                
                # right to left
                if (not valid(x, y+1) or board[x][y+1] == '#') and (not valid(x, y-W) or board[x][y-W] == '#') and place(x, y, word, [0, -1]):
                    return True
                
                # top to bottom
                if (not valid(x-1, y) or board[x-1][y] == '#') and (not valid(x+W, y) or board[x+W][y] == '#') and place(x, y, word, [1, 0]):
                    return True
                
				# bottom to top
                if (not valid(x+1, y) or board[x+1][y] == '#') and (not valid(x-W, y) or board[x-W][y] == '#') and place(x, y, word, [-1, 0]):
                    return True
                
        return False
