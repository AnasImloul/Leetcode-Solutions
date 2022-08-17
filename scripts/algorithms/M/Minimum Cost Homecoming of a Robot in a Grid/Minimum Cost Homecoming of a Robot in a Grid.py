class Solution:
    def minCost(self, startPos: List[int], homePos: List[int], rowCosts: List[int], colCosts: List[int]) -> int:
        def getRange(left, right, array):
            if left > right:
                right, left = left, right
            return sum((array[i] for i in range(left,right+1)))
        
        totalRowCost = getRange(startPos[0], homePos[0], rowCosts)
        totalColCost = getRange(startPos[1], homePos[1], colCosts)
        
        #Don't pay for the position you start out on
        return totalRowCost + totalColCost - rowCosts[startPos[0]] - colCosts[startPos[1]]
