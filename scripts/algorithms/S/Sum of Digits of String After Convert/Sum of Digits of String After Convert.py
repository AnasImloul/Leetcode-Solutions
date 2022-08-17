class Solution:
    def getLucky(self, s: str, k: int) -> int:
        nums = [str(ord(c) - ord('a') + 1) for c in s]
        for _ in range(k):
            nums = str(sum(int(digit) for num in nums for digit in num))
        return nums

