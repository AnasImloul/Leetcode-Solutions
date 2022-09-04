# Runtime: 2982 ms (Top 22.53%) | Memory: 27.5 MB (Top 95.77%)
class Solution:
    def stoneGameIX(self, stones: List[int]) -> bool:
        u, d, t = 0, 0, 0
        for stone in stones:
            if stone % 3 == 1:
                u += 1
            elif stone % 3 == 2:
                d += 1
            else:
                t += 1
        if not u and d <= 2 or u <= 2 and not d: #situation 1 part 2
            return False
        if not u and d > 2 or u > 2 and not d: #situation 1 part 1
            if not t % 2:
                return False
            else:
                return True
        if u == d or abs(u - d) <= 2: #situation 2 and situation 3
            if t % 2:
                return False
            else:
                return True
        return True #default situation