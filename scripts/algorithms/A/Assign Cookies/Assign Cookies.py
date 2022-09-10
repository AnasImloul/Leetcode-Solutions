# Runtime: 437 ms (Top 8.80%) | Memory: 15.9 MB (Top 13.77%)
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        cont = 0
        c = 0
        k = 0
        while k< len(s) and c < len(g):
            if s[k] >= g[c]:
                c+=1
                k+=1
                cont+=1
            else:
                k+=1
        return cont