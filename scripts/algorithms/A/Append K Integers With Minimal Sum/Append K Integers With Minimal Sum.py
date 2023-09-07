# Runtime: 563 ms (Top 89.1%) | Memory: 31.37 MB (Top 44.5%)

class Solution:
    def minimalKSum(self, nums: List[int], k: int) -> int:
        ans = k*(k+1)//2
        prev = -inf 
        for x in sorted(nums): 
            if prev < x: 
                if x <= k: 
                    k += 1
                    ans += k - x
                else: break
                prev = x
        return ans 