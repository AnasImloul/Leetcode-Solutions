# Runtime: 549 ms (Top 98.6%) | Memory: 23.43 MB (Top 9.7%)

class Solution:
    def countTriplets(self, nums: List[int]) -> int:
        freq = defaultdict(int)
        for x in nums: 
            for y in nums: 
                freq[x&y] += 1
        
        ans = 0
        for x in nums: 
            mask = x = x ^ 0xffff
            while x: 
                ans += freq[x]
                x = mask & (x-1)
            ans += freq[0]
        return ans 