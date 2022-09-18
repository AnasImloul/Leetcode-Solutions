# Runtime: 993 ms (Top 30.00%) | Memory: 25.8 MB (Top 18.75%)
class Solution:
    def lastSubstring(self, s: str) -> str:
        n = len(s)
        cmax = max(s)
        indexes = [ i for i,c in enumerate(s) if c == cmax ]
        gap = 1
        while len(indexes) > 1:
            new_indexes = []
            cmax = max(s[i+gap] for i in indexes if i+gap < n)
            for i,st in enumerate(indexes):
                if i > 0 and indexes[i-1] + gap == st: continue
                if st + gap < n and s[st + gap] == cmax:new_indexes.append(st)
            indexes = new_indexes
            gap += 1
        return s[indexes[0]:]