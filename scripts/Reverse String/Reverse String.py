class Solution(object):
    def reverseString(self, s):
        for i in range(len(s)):
            s.insert(i,s.pop())
        return s
