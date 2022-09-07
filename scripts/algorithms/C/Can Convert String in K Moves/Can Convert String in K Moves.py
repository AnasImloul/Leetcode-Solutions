# Runtime: 285 ms (Top 92.79%) | Memory: 15.1 MB (Top 75.68%)
class Solution:
    def canConvertString(self, s: str, t: str, k: int) -> bool:
        if len(s) != len(t):
            return False

        cycles, extra = divmod(k, 26)
        shifts = [cycles + (shift <= extra) for shift in range(26)]

        for cs, ct in zip(s, t):
            shift = (ord(ct) - ord(cs)) % 26
            if shift == 0:
                continue
            if not shifts[shift]:
                return False
            shifts[shift] -= 1

        return True