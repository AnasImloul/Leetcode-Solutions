# Runtime: 198 ms (Top 78.1%) | Memory: 18.99 MB (Top 16.6%)

class Solution:
    def findShortestSubArray(self, nums):
        # Group indexes by element type
        d = defaultdict(list)
        for i,x in enumerate(nums):
            d[x].append(i)
        #
        # Find highest Degree
        m = max([ len(v) for v in d.values() ])
        #
        # Find shortest span for max. degree
        best = len(nums)
        for v in d.values():
            if len(v)==m:
                best = min(best,v[-1]-v[0]+1)
        return best