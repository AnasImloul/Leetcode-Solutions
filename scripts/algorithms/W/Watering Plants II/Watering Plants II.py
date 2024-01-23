// Runtime: 591 ms (Top 95.38%) | Memory: 31.60 MB (Top 92.31%)

class Solution:
    def minimumRefill(self, plants: List[int], capacityA: int, capacityB: int) -> int:
        ans = 0 
        lo, hi = 0, len(plants)-1
        canA, canB = capacityA, capacityB
        while lo < hi: 
            if canA < plants[lo]: ans += 1; canA = capacityA
            canA -= plants[lo]
            if canB < plants[hi]: ans += 1; canB = capacityB
            canB -= plants[hi]
            lo, hi = lo+1, hi-1
        if lo == hi and max(canA, canB) < plants[lo]: ans += 1
        return ans 
