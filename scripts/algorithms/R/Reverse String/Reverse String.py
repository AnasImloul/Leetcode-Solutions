# Runtime: 1141 ms (Top 5.04%) | Memory: 18.3 MB (Top 98.71%)

class Solution(object):
    def reverseString(self, s):
        for i in range(len(s)):
            s.insert(i,s.pop())
        return s