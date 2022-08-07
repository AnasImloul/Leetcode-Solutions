class Solution:
    def firstBadVersion(self, n: int) -> int:
        fast, slow = int(n/2), n
        diff = abs(fast-slow)
        while isBadVersion(fast) == isBadVersion(slow) or diff > 1:
            fast, slow = fast + (-1)**isBadVersion(fast) * (int(diff/2) or 1), fast
            diff = abs(fast-slow)
        return fast if isBadVersion(fast) else slow
