class Solution:
    def validTicTacToe(self, board: List[str]) -> bool:
                                            # The two criteria for a valid board are:
                                            #   1) num of Xs - num of Os is 0 or 1
                                            #   2) X is not a winner if the # of moves is even, and
                                            #      O is not a winner if the # of moves is odd.

        d = {'X': 1, 'O': -1, ' ': 0}               # transform the 1x3 str array to a 1x9 int array
        s = [d[ch] for ch in ''.join(board)]        # Ex: ["XOX"," X ","   "] --> [1,-1,1,0,1,0,0,0,0]
        sm = sum(s)

        if sm>>1: return False                                      # <-- criterion 1
        
        n = -3 if sm == 1 else 3                                    # <-- criterion 2.
        if n in {s[0]+s[1]+s[2], s[3]+s[4]+s[5], s[6]+s[7]+s[8], 
                 s[0]+s[3]+s[6], s[1]+s[4]+s[7], s[2]+s[5]+s[8],         # the elements of the set are 
                 s[0]+s[4]+s[8], s[2]+s[4]+s[6]}: return False           # the rows, cols, and diags
        
        return True                                                 # <-- both criteria are true