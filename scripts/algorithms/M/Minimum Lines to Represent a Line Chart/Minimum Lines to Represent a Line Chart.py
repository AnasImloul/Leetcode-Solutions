class Solution:
    def minimumLines(self, stockPrices: List[List[int]]) -> int:
        stockPrices.sort()
        gradient = None
        res = 0
        for cur,nxt in pairwise(stockPrices):
            newGradient = (nxt[1]-cur[1])/(nxt[0]-cur[0]) # :(
            if newGradient != gradient:
                gradient = newGradient
                res += 1
        return res
