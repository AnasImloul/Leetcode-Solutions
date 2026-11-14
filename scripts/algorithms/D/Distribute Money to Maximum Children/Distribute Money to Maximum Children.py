# Runtime: 3 ms (Top 55.59%) | Memory: 19.20 MB (Top 45.53%)

class Solution:
    def distMoney(self, money: int, children: int) -> int:

        if money < children: return -1          #   <-- More children than dollars

        n = 8 * children - money                #   <-- Enough dollars for all children 
                                                #       to get at least 8 dollars; one
        if n <= 0: return children - (n < 0)    #       child may get more than 8 dollars        

        ans, rem = divmod(money-children,7)     #   <-- Every child gets a dollar, then ans
                                                #       children get an additional 7 dollars 

        return ans - ((ans, rem) == (children - 1, 3))
                                                #   <-- Decrement the ans if only one child 
                                                #       gets less than 8 dollars and that 
                                                #       child gets exactly 4 dollars
