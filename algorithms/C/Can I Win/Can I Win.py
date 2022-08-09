class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        remainder = [i+1 for i in range(maxChoosableInteger)] # numbers
        @cache
        def can_win(total, remainder):
            if total >= desiredTotal:
                return False # total is already exceed the desiredTotal. Opponent won. 
            
            for num in remainder:
                if can_win(total + num, tuple([n for n in remainder if n != num])) == False: # if opponent lose, I win(return True)
                    return True
            return False 
        
        if desiredTotal == 0: 
            return True 
        if sum(remainder) < desiredTotal: # Both of two cannot win.
            return False 
        return can_win(0, tuple(remainder))
