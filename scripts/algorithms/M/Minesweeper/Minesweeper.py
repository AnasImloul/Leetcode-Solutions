class Solution:
    def calMines(self,board,x,y):
        directions = [(-1,-1), (0,-1), (1,-1), (1,0), (1,1), (0,1), (-1,1), (-1,0)]
        mines = 0
        for d in directions:
            r, c = x+d[0],y+d[1]
            if self.isValid(board,r,c) and (board[r][c] == 'M' or board[r][c] == 'X'):
                mines+=1
        return mines

    def updateBoard(self, board: List[List[str]], click: List[int]) -> List[List[str]]:
        x,y = click[0],click[1]
        options = []
        if board[x][y] == "M":
            board[x][y] = "X"
        else:
            count = self.calMines(board,x,y)
            if count == 0:
                board[x][y] = "B"
                for r in range(x-1,x+2):
                    for c in range(y-1,y+2):
                        if self.isValid(board,r,c) and board[r][c]!='B':
                            self.updateBoard(board,[r,c])
            else:
                board[x][y] = str(count)

        return board
    
    
    def isValid(self,board,a,b):
            return 0<=a<len(board) and 0<=b<len(board[0])


        