# Runtime: 7 ms (Top 8.99%) | Memory: 19.20 MB (Top 52.81%)

class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        def findLongestConsecutiveElements(numsSet):
            res = 1
            for num in numsSet:
                count = 1
                current = num
                while current+1 in numsSet:
                    current += 1
                    count += 1
                res = max(res, count)
            return res

        res = 1
        if len(hBars) == 0 or len(vBars) == 0: return 1
        hSet, vSet = set(hBars), set(vBars)
        maxHBars, maxVBars = findLongestConsecutiveElements(hSet), findLongestConsecutiveElements(vSet)
        return (min(maxHBars, maxVBars) + 1) ** 2
