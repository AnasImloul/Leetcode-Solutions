# Runtime: 66 ms (Top 24.00%) | Memory: 13.8 MB (Top 70.18%)
class Solution:
    def splitString(self, s: str, last_val: int = None) -> bool:
        # Base case, remaining string is a valid solution
        if last_val and int(s) == last_val - 1:
            return True

        # Iterate through increasingly larger slices of s
        for i in range(1, len(s)):
            cur = int(s[:i])
            # If current slice is equal to last_val - 1, make
            # recursive call with remaining string and updated last_val
            if last_val is None or cur == last_val - 1:
                if self.splitString(s[i:], cur):
                    return True

        return False