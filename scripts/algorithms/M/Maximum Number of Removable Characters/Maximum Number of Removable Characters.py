// Runtime: 957 ms (Top 98.8%) | Memory: 28.80 MB (Top 96.39%)

class Solution:
    def maximumRemovals(self, s: str, p: str, removable: List[int]) -> int:
        l, r = 0, len(removable)

        def isEnough(k):
            s_arr = list(s)
            for i in removable[:k]:
                s_arr[i] = ''
            return isSubsequence(p, s_arr)
            
        def isSubsequence(s, t):
            t = iter(t)
            return all(c in t for c in s)

        while l < r:
            m = (l+r+1)//2
            if isEnough(m):
                l = m
            else:
                r = m - 1
        
        return l
