// Runtime: 114 ms (Top 97.78%) | Memory: 16.60 MB (Top 73.33%)

class Solution:
    def maximumBobPoints(self, numArrows: int, aliceArrows: List[int]) -> List[int]:
        max_score = [0, None]
        def calc(i, remaining, score, arrows):
		    # Base case. Update max score.
            if remaining == 0 or i == -1:
                if score > max_score[0]:
                    max_score[0] = score
                    max_score[1] = arrows[:]
                return

			# Special handling for the last section. Use up all the arrows.
            if i == 0:
                arrows[i] = remaining
                calc(i - 1, 0, score + i, arrows)
                arrows[i] = 0
                return

		    # Try to compete with Alice if there are enough arrows.
            arrowsNeeded = aliceArrows[i] + 1
            if remaining >= arrowsNeeded:
                arrows[i] = arrowsNeeded
                calc(i - 1, remaining - arrowsNeeded, score + i, arrows)
                arrows[i] = 0

            # Skip this section and go to the next section.
            calc(i - 1, remaining, score, arrows)
        
		# Kick off the recursion
        calc(len(aliceArrows) - 1, numArrows, 0, [0 for _ in aliceArrows])
        return max_score[1]
