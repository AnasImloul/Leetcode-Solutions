# Runtime: 61 ms (Top 15.28%) | Memory: 13.8 MB (Top 62.83%)
class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        if word not in sequence:
            return 0

        left = 1
        right = len(sequence) // len(word)
        while left <= right:
            mid = (left + right) // 2
            if word * mid in sequence:
                left = mid + 1
            else:
                right = mid - 1

        return left - 1