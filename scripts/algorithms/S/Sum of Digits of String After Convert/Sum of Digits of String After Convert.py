# Runtime: 78 ms (Top 10.28%) | Memory: 14 MB (Top 20.56%)
class Solution:
    def getLucky(self, s: str, k: int) -> int:
        nums = [str(ord(c) - ord('a') + 1) for c in s]
        for _ in range(k):
            nums = str(sum(int(digit) for num in nums for digit in num))
        return nums
