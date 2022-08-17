import math


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        n = len(piles)
        if n == h:
            return max(piles)
        piles.sort(reverse=True)
        extra = h - n # each pile takes at least 1 hour
        total_amount = 0
        for i, pile in enumerate(piles):
            if extra < i+1: 
                return pile # 1 hour lowest resolution 

            total_amount += pile
            tmp_k = math.ceil(total_amount / (extra + i + 1))
            if i+1 < n and tmp_k > piles[i+1] or i+1 == n:
                return tmp_k # round up
