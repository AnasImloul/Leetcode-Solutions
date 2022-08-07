class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        p, s = list(pattern), list(s.split(" "))

        return len(s) == len(p) and len(set(zip(p, s))) == len(set(s)) == len(set(p))

