# Runtime: 236 ms (Top 95.16%) | Memory: 16 MB (Top 85.69%)
class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        allowed = set(allowed)
        count = 0

        for word in words:
            for letter in word:
                if letter not in allowed:
                    count += 1
                    break

        return len(words) - count