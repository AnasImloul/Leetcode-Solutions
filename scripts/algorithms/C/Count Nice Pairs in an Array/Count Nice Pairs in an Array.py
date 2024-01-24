// Runtime: 500 ms (Top 94.22%) | Memory: 26.90 MB (Top 76.37%)

class Solution:
    def countNicePairs(self, nums: List[int]) -> int:
        res = 0
        count = {}
        mod = 10**9 + 7
        
        for n in nums:
            rev = int(str(n)[::-1])
            cur = count.get(n - rev, 0)
            res += cur
            count[n - rev] = 1 + cur

        return res % mod
