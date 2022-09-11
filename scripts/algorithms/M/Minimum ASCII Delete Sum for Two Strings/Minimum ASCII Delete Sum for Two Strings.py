# Runtime: 4020 ms (Top 5.03%) | Memory: 205.5 MB (Top 14.36%)
class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        m, n, lookup = len(s1), len(s2), {}
        def fun(i, j):
            if (i,j) in lookup:
                return lookup[(i,j)]
            if i < 0:
                return sum([ord(char) for char in s2[:j+1]])
            if j < 0:
                return sum([ord(char) for char in s1[:i+1]])
            if s1[i] == s2[j]:
                res = fun(i-1, j-1)
            else:
                res = min(ord(s1[i]) + fun(i-1,j), ord(s2[j]) + fun(i,j-1))
            lookup[(i,j)] = res
            return lookup[(i,j)]
        return fun(m-1, n-1)