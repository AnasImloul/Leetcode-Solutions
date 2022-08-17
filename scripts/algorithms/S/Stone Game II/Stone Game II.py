class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        dp = {} 
        def recursion(index,M):
            # if we reached to the end we cannot score any value
            if index == n:
                return 0
            # we search if we have solved the same case earlier
            if (index,M) in dp:
                return dp[(index,M)] 
            # total remaining score is the sum of array from index to the end
            total = sum(piles[index:])           
            # if we can take the complete array it is the best choice
            if index + 2*M >= n :return total
            # my_score is the score we are getting as the player who is playing
            my_score = 0
            for x in range(index,index+2*M):
                # opponent score will be calculated by next recursion
                opponent_score = recursion(x+1,max(M,x-index+1))
                # my_score is the remaining value of total - opponent_score
                my_score = max(my_score,total - opponent_score)          
            # this is memoization part
            dp[(index,M)] = my_score
            # return the score
            return my_score
        
        return recursion(0,1)
