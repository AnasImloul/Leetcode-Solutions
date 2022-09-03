# Runtime: 73 ms (Top 5.29%) | Memory: 13.8 MB (Top 58.42%)
class Solution(object):
    def replaceDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        res = []

        for i in range(len(s)):
            if i % 2 == 0:
                res.append(s[i])
            if i % 2 == 1:
                res.append( chr(ord(s[i-1]) + int(s[i])) )

        return ''.join(res)