class Solution:
    def divisorGame(self, n: int) -> bool:
                
        """
        let's forget about Alice and Bob for a second and just concentrate on the n and plays
        if played optimally :
        
        1 - player at 1 will loose since no factors
        2 - player at 2 will win by choosing 1
        3 - player at 3 will loose always since he/she has to choose 1. and then next player will always win because they are at 2
        4 - player at 4 will win by choosing 1 as a factor as next player will have to play at 3
        5 - player at 5 will loose because he has to choose 1, and player at 4 will always win
        6 - player at 6 will always win by choosing 3 as a factor
        7 - player at 7 will have to choose 1, and hence result 6 will make player at 6 to win
        8 - player at 8 can choose 1 and win always
        .
        .
        .
        .
        Pattern detected
        
        Now, since Alice is the first player we can return bool values accordingly
        
        
        """
        
        return n%2 == 0
        
        
