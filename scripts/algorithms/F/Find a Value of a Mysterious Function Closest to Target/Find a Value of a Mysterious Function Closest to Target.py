# Runtime: 1091 ms (Top 49.0%) | Memory: 27.44 MB (Top 83.6%)

class Solution:
    def closestToTarget(self, arr: List[int], target: int) -> int:
        ans, seen = inf, set()
        for x in arr: 
            seen = {ss & x for ss in seen} | {x}
            ans = min(ans, min(abs(ss - target) for ss in seen))
        return ans 