# Runtime: 2544 ms (Top 32.35%) | Memory: 73.6 MB (Top 48.94%)
class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:

        items.sort()
        dic = dict()
        res = []
        gmax = 0
        for p,b in items:
            gmax = max(b,gmax)
            dic[p] = gmax

        keys = sorted(dic.keys())
        for q in queries:
            ind = bisect.bisect_left(keys,q)
            if ind<len(keys) and keys[ind]==q:
                res.append(dic[q])
            elif ind==0:
                res.append(0)
            else:
                res.append(dic[keys[ind-1]])

        return res