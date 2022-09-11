# Runtime: 104 ms (Top 89.12%) | Memory: 14 MB (Top 35.48%)
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:

        hrow = {}
        hcol = {}
        hbox = defaultdict(list)

        #CHECK FOR DUPLICATES ROWWISE
        for i in range(9):
            for j in range(9):

                #JUST THAT THE DUPLICATE SHOULDNT BE ","
                if board[i][j] != '.':

                    if board[i][j] not in hrow:
                        hrow[board[i][j]] = 1

                    else:
                        return False

            #CLEAR HASHMAP FOR THIS ROW
            hrow.clear()
        print("TRUE1")
        #CHECK FOR DUPLICATES COLUMNWISE

        for i in range(9):
            for j in range(9):

                #JUST THAT THE DUPLICATE SHOULDNT BE ","
                if board[j][i] != '.':

                    if board[j][i] not in hcol:
                        hcol[board[j][i]] = 1

                    else:
                        return False

        #CLEAR HASHMAP FOR THIS COL

            hcol.clear()

        print('TRUE2')

        #CHECK DUPLICATE IN BOX, THIS IS WHERE KEY DESIGN SKILLS COME INTO PLAY, FOR SUDOKU YOU COMBINE ROW INDICES AND COL INDICES

        for i in range(9):
            for j in range(9):

                i_3 = i //3
                j_3 = j//3

                # print(hbox)
                if board[i][j] != '.':

                #CHECK ELEMENT OF ORIGINAL INDICE present in key i_3 , j_3
                    if board[i][j] not in hbox[i_3 , j_3]:
# #CHECKED IN NEW KEY
                        hbox[i_3 ,j_3 ]= hbox[i_3 ,j_3 ] + [board[i][j]]

                    else:
                        return False

        return True
