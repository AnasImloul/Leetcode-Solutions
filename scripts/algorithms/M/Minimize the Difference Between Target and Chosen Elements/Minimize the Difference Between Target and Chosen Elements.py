// Runtime: 2497 ms (Top 82.35%) | Memory: 20.40 MB (Top 18.04%)

class Solution:
    def minimizeTheDifference(self, mat: List[List[int]], target: int) -> int:
        
        # store the mxn size of the matrix
        m = len(mat)
        n = len(mat[0])
        
        dp = defaultdict(defaultdict)
        
        # Sorting each row of the array for more efficient pruning
        # Note:this purely based on the observation on problem constraints (although interesting :))
        for i in range(m):
            mat[i] = sorted(mat[i])
        
        # returns minimum absolute starting from from row i to n-1 for the target
        globalMin = float("inf")
        def findMinAbsDiff(i,prevSum):
            nonlocal globalMin
            if i == m:
                globalMin = min(globalMin, abs(prevSum-target))
                return abs(prevSum-target)
            
            # pruning step 1
            # because the array is increasing & prevSum & target will always be positive
            if prevSum-target > globalMin:
                return float("inf")
            
            
            if (i in dp) and (prevSum in dp[i]):
                return dp[i][prevSum]
            
            minDiff = float("inf")
            # for each candidate select that and backtrack
            for j in range(n):
                diff = findMinAbsDiff(i+1, prevSum+mat[i][j])
                # pruning step 2 - break if we found minDiff 0 --> VERY CRTICIAL
                if diff == 0:
                    minDiff = 0
                    break
                minDiff = min(minDiff, diff)
            
            dp[i][prevSum] = minDiff
            return minDiff
        
        return findMinAbsDiff(0, 0)
