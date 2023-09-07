# Runtime: 506 ms (Top 96.6%) | Memory: 30.16 MB (Top 47.7%)

class Solution:
    def getWinner(self, arr: List[int], k: int) -> int:
        winner = arr[0]
        wins = 0
        for i in range(1,len(arr),1):
            if(winner > arr[i]): wins+=1  # increment wins count   
            else:
                wins = 1    # new winner
                winner = arr[i]
            if(wins == k): break    # if wins count is k, then return winner
                
        return winner