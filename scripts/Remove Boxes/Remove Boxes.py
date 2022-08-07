from functools import cache

class Solution:
    def removeBoxes(self, boxes: List[int]) -> int:
        colors, consecutive = [], []
        cnt = 0
        prev_color = None
        for color in boxes:
            if prev_color is None:
                cnt = 1
            elif color != prev_color:
                colors.append(prev_color)
                consecutive.append(cnt)
                cnt = 1
            else:
                cnt += 1
            prev_color = color
        colors.append(prev_color)
        consecutive.append(cnt)
                
        @cache
        def dp(i, j, carry_over):
            if i == j:
                return 0
            
            # option 1: remove i and calculate rest of score
            best = (consecutive[i] + carry_over) ** 2 + dp(i+1, j, 0)
            
            # option 2: Remove all boxes in between i and a similar colored box x,
			# so that we can remove i+x.
            for x in range(i+1, j):
                if colors[i] == colors[x]:
                    best = max(best, dp(i+1, x, 0) + dp(x, j, consecutive[i] + carry_over))
            return best
        
        return dp(0, len(colors), 0)
