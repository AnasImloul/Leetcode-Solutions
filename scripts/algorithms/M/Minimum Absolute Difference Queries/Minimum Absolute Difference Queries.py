class Solution:
    def minDifference(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        # location of number
        loc = defaultdict(list)
        for i, num in enumerate(nums):
            loc[num].append(i)
        
        # start from sorted key thus keep tracking minimum difference
        k = sorted(loc)
        
        res = []
        for a, b in queries:
            cands = []
            ans = float('inf')
            for c in k:
                # left and right range overlap means no available locations in range
                if bisect.bisect_left(loc[c], a) == bisect.bisect(loc[c], b): continue
                if cands: 
					ans = min(ans, c - cands[-1])
                cands.append(c)
            if ans == float('inf'): ans = -1
            res.append(ans)
        return res