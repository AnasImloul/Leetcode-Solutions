class Solution:
    def minSwaps(self, s: str) -> int:
        res, bal = 0, 0
        for ch in s:
            bal += 1 if ch == '[' else -1
            if bal == -1:
                res += 1
                bal = 1
        return res
