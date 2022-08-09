from math import comb
class Solution:
    def kthSmallestPath(self, destination: List[int], k: int) -> str:
        i,j = destination
        
        @lru_cache(None)
        def helper(i,j,k):
            if k == 1:
                return "H"*j+"V"*i
            else:
                horizontal = comb(i+j-1,j-1)
                if k <= horizontal:
                    return "H" + helper(i,j-1,k)
                else:
                    return "V" + helper(i-1,j,k-horizontal)
        
        return helper(i,j,k)
