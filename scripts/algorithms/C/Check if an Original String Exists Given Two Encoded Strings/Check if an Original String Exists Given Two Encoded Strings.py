// Runtime: 1026 ms (Top 83.52%) | Memory: 55.5 MB (Top 82.18%)
from functools import lru_cache
class Solution:
    def possiblyEquals(self, s1: str, s2: str) -> bool:

        def getValidPrefixLength(s,start):
            end = start
            while end < len(s) and s[end].isdigit(): end += 1
            return end

        @lru_cache(None)
        def possibleLengths(s):
            """Return all possible lengths represented by numeric string s."""
            ans = {int(s)}
            for i in range(1, len(s)):
                # add all lengths by splitting numeric string s at i
                ans |= {x+y for x in possibleLengths(s[:i]) for y in possibleLengths(s[i:])}
            return ans

        @lru_cache(None)
        def dp(i, j, diff):
            """Return True if s1[i:] matches s2[j:] with given differences."""

            # If both have reached end return true if none of them are leading
            if i == len(s1) and j == len(s2): return diff == 0

            # s1 has not reached end and s1 starts with a digit
            if i < len(s1) and s1[i].isdigit():
                i2 = getValidPrefixLength(s1,i)
                for L in possibleLengths(s1[i:i2]):
                    # substract since lead of s2 decreases by L
                    if dp(i2, j, diff-L): return True

            # s2 has not reached end and s2 starts with a digit
            elif j < len(s2) and s2[j].isdigit():
                j2 = getValidPrefixLength(s2,j)
                for L in possibleLengths(s2[j:j2]):
                    # add since lead of s2 increase by L
                    if dp(i, j2, diff+L): return True

            # if none of them have integer prefix or a lead over the other
            elif diff == 0:
                # if only one of them has reached end or current alphabets are not the same
                if i == len(s1) or j == len(s2) or s1[i] != s2[j]: return False
                # skip same alphabets
                return dp(i+1, j+1, 0)

            # if none of them have integer prefix & s2 lead over s1
            elif diff > 0:
                # no s1 to balance s2's lead
                if i == len(s1): return False
                # move s1 pointer forward and reduce diff
                return dp(i+1, j, diff-1)

            # if none of them have integer prefix & s1 lead over s2
            else:
                # no s2 to balance s1's lead
                if j == len(s2): return False
                # move s2 pointer forward and increase diff
                return dp(i, j+1, diff+1)

        # start with starts of both s1 and s2 with no lead by any of them
        return dp(0, 0, 0)