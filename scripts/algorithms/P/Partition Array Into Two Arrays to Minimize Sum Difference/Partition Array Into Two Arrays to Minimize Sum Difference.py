class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        n = len(nums)//2
        left, right = nums[:n], nums[n:]
        lsum, rsum = sum(left), sum(right)
        
        ans = inf
        for i in range(n+1): 
            vals = sorted(2*sum(combo)-lsum for combo in combinations(left, i))
            for combo in combinations(right, n-i): 
                diff = 2*sum(combo) - rsum
                k = bisect_left(vals, -diff)
                if k: ans = min(ans, abs(vals[k-1] + diff))
                if k < len(vals): ans = min(ans, abs(vals[k] + diff))
        return ans 
