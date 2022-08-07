class Solution:
    def countBattleships(self, board: List[List[str]]) -> int:
        
        m = len(board)
        n = len(board[0])
        res = 0
        
        pole = [ [True for i in range(n)] for j in range(m) ]
        
        for i in range(m):
            for j in range(n):
                if board[i][j] == 'X' and pole[i][j]:
                    for z in range(i+1, m):
                        if board[z][j] == 'X':
                            pole[z][j] = False
                        else:
                            break
                            
                    for z in range(j+1, n):
                        if board[i][z] == 'X':
                            pole[i][z] = False
                        else:
                            break
                    
                    
                    res += 1
                

        
        return res
