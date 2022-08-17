class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
		# Checking for possible case to the right of Rook
        def right_position(n,i):
            List = i[0:n][::-1] # taking list to the right of rook
            pIndex,bIndex = -1,-1
            if 'p' in List: # Checking if  'p' in list   
                pIndex = List.index('p')
            if 'B' in List: # Checking if 'B' in list
                bIndex = List.index('B')
            print(bIndex,pIndex,List)
            if bIndex == -1 and pIndex >-1: # if list does not have 'B' and have 'p'
                return True
            if pIndex == -1: # if list does not have 'p'
                return False
            return bIndex>pIndex 
        def left_position(n,i):
            List = i[n+1:]# taking list to the right of rook
            pIndex,bIndex = -1,-1
            if 'p' in List:
                pIndex = List.index('p')
            if 'B' in List:
                bIndex = List.index('B')
            print(bIndex,pIndex,List)
            if bIndex == -1 and pIndex >-1:
                return True
            if pIndex == -1:
                return False
            return bIndex>pIndex
        Count = 0
		# Checking for possibilites in row
        for i in board:
            if 'R' in i:
                print(i)
                n = i.index('R')
                if left_position(n,i):
                    Count += 1
                if right_position(n,i):
                    Count += 1
        Col = []
		# checking for possibilites in col
        for i in range(0,len(board)):
            Col.append(board[i][n]) # taking the elements from the same col of Rook
        n = Col.index('R')
        if left_position(n,Col):
            Count += 1
        if right_position(n,Col):
            Count += 1
        return Count
