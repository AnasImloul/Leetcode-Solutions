class Solution:
    def maximumBobPoints(self, numArrows: int, aliceArrows: List[int]) -> List[int]:
        self.bestScore = 0
        self.bestBobArrows = None
        
        def backtracking(k, remainArrows, score, bobArrows):
            if k == 12:
                if score > self.bestScore:
                    self.bestScore = score
                    self.bestBobArrows = bobArrows[::]
                return
            
            backtracking(k+1, remainArrows, score, bobArrows)  # Bob loses
            
            # Bob wins
            arrowsNeeded = aliceArrows[k] + 1
            if remainArrows >= arrowsNeeded:
                old = bobArrows[k]
                bobArrows[k] = arrowsNeeded  # set new
                backtracking(k+1, remainArrows - arrowsNeeded, score + k, bobArrows)
                bobArrows[k] = old  # backtrack
                
        backtracking(0, numArrows, 0, [0] * 12)
		# In case of having remain arrows then it means in all sections Bob always win 
        # then we can distribute the remain to any section, here we simple choose first section.
        self.bestBobArrows[0] += numArrows - sum(self.bestBobArrows)
        return self.bestBobArrows
