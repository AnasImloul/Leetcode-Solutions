class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row=[set() for i in range(9)]
        col=[set() for i in range(9)]
        box=[set() for i in range(9)]
        #print(row)
        
        for r in range(9):
            for c in range(9):
                val=board[r][c]
                if val.isdigit():
                    if val in row[r]:
                        return False
                    row[r].add(val)
                    if val in col[c]:
                        return False
                    col[c].add(val)
					#find the box number with r,c value
                    r1=r//3
                    if r1==1:  r1=3
                    if r1==2:r1=6
                    c1=c//3
                    b=r1+c1
                    if val in box[b]:
                        return False
                    box[b].add(val)                    
        return True
                    
