class Solution:
    def closestCost(self, baseCosts: List[int], toppingCosts: List[int], target: int) -> int:
        self.ans = self.diff = float('inf')
        
        n = len(baseCosts)
        m = len(toppingCosts)
        
        
        def solve(sum, target, indx):
            if abs(sum - target) < self.diff:
                self.diff = abs(sum - target)
                self.ans = sum
            elif abs(sum - target) == self.diff:
                self.ans = min(self.ans, sum)
            
            
            if indx == m:
                return
            
            i = indx
            for count in range(3):
                sum += toppingCosts[i]*count
                solve(sum,target,i+1)
                sum -= toppingCosts[i]*count
        
        for i in baseCosts:
            solve(i, target, 0)
        return self.ans
