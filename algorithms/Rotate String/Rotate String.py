# Runtime: 33 ms, faster than 90.10% of Python3 online submissions for Rotate String.
# Memory Usage: 13.8 MB, less than 97.64% of Python3 online submissions for Rotate String.

class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        for x in range(len(s)):
            s = s[-1] + s[:-1]
            if (goal == s):
                return True
        return False
