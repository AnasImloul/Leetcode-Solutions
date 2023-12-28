// Runtime: 867 ms (Top 95.98%) | Memory: 21.70 MB (Top 17.82%)

class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        res = odd = even = 0
        for x in arr:
            even += 1
            if x % 2:
                odd, even = even, odd
            res = (res + odd) % 1000000007             
        return res            
