// Runtime: 29 ms (Top 94.21%) | Memory: 16.40 MB (Top 63.56%)

class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        l, r = list(), list()
        for i in s:
            if i == "(":
                l.append(i)
            else:
                if l:
                    l.pop()
                else:
                    r.append(i)
        return len(l) + len(r)
