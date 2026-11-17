# Runtime: 0 ms (Top 100.00%) | Memory: 19.20 MB (Top 75.24%)

class Solution:
    def isAcronym(self, words: List[str], s: str) -> bool:

        return ''.join(word[0] for word in words) == s
