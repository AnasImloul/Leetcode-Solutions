# Runtime: 30 ms (Top 97.1%) | Memory: 16.43 MB (Top 14.4%)

class Solution:
    def flipLights(self, n: int, m: int) -> int:
        # Reduce n to at most 3, since any action performed more than 3 times
        # will result in a pattern that has already been counted
        n = min(n, 3)
        if m == 0:
            return 1
        elif m == 1:
            # For m=1, there are only 2 outcomes for n=1, 3 outcomes for n=2, and 4 outcomes for n=3
            return [2, 3, 4][n - 1]
        elif m == 2:
            # For m=2, there are only 2 outcomes for n=1, 4 outcomes for n=2, and 7 outcomes for n=3
            return [2, 4, 7][n - 1]
        else:
            # For m>=3, there are only 2 outcomes for n=1, 4 outcomes for n=2, and 8 outcomes for n=3
            return [2, 4, 8][n - 1]
