class Solution:
    def maximumSubsequenceCount(self, text: str, pattern: str) -> int:
        total = count_a = count_b = 0
        for c in text:
            if c == pattern[1]:
                total += count_a
                count_b += 1
            if c == pattern[0]:
                count_a += 1
        
        return total + max(count_a, count_b)
