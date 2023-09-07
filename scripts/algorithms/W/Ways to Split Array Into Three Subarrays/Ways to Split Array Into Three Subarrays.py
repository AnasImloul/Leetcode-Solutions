# Runtime: 1271 ms (Top 38.4%) | Memory: 29.79 MB (Top 48.0%)

class Solution:
    def waysToSplit(self, nums: List[int]) -> int:
        prefix = [0]
        for x in nums: prefix.append(prefix[-1] + x)
        
        ans = 0
        for i in range(1, len(nums)): 
            j = bisect_left(prefix, 2*prefix[i])
            k = bisect_right(prefix, (prefix[i] + prefix[-1])//2)
            ans += max(0, min(len(nums), k) - max(i+1, j))
        return ans % 1_000_000_007