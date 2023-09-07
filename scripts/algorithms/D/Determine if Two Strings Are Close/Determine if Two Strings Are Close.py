# Runtime: 137 ms (Top 70.4%) | Memory: 17.77 MB (Top 49.0%)

from collections import Counter

class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        return set(word1) == set(word2) and Counter(Counter(word1).values()) == Counter(Counter(word2).values())