# Runtime: 2807 ms (Top 93.1%) | Memory: 139.81 MB (Top 61.7%)

class Solution:
    def specialPerm(self, nums: List[int]) -> int:

        mod, d, n = 1_000_000_007, defaultdict(set), len(nums)
        
        for i,j in product(range(n),range(n)):
            if not (nums[i]%nums[j]) and i != j:
                d[i].add(j)
                d[j].add(i)
                        
        @lru_cache(None)
        def dfs(i, mask):

            if mask.bit_count() == n: return 1

            return sum(dfs(j, mask|(1<<j)) 
                       for j in d[i] if not mask&(1<<j))

        return sum(dfs(k, 1<<k) for k in range(n)) %mod