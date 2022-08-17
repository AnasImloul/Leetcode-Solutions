class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        piles.sort()
        n = len(piles)
        k = n // 3
        i, j = 0, 2
        ans = 0
        while i < k:
            ans += piles[n-j]
            j += 2
            i +=1
        return ans