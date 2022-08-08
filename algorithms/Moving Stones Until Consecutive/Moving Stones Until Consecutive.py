class Solution:
    def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
        
        # max is just the empty slots number, 
        # for example,  2, 4, 8. Empty has (8 - 2 - 1) - 1
        # in the parenthesis, it is the total slots in (2, 8), then we subtract the middle 4 also.
        maxx = (max(a,b,c) - min(a,b,c) - 1) - 1
		
		# continuous, like 2, 3, 4
        if maxx == 0: 
            return [0, 0]
        
        # Example, 1,  2,  10, then minimum is 1, we push 10 to the 3rd position in one move
        if abs(a-b) == 1 or abs(b-c) == 1 or abs(a-c) == 1:
            return [1, maxx]
        
        # Example, 2, 4, 11, then minimum is also 1, we push 11 to the 3rd position in one move.
        if abs(a-b) == 2 or abs(b-c) == 2 or abs(a-c) == 2:
            return [1, maxx]
        
        # Others, example,   2, 5, 9, minimum is 2, we push 2 to the 4th position, 
        # then push 9 to the 6th position.
        return [2, maxx]
