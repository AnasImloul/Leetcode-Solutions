# Runtime: 87 ms (Top 42.12%) | Memory: 14.3 MB (Top 6.17%)
class Solution:
    def _get_char_counts(self, s: str) -> dict[str]:
        """builds a dict of letters : count"""
        d = {}
        for i in s:
            d[i] = d.get(i,0)+1
        return d

    def commonChars(self, words: list[str]) -> list[str]:
        """returns a string of letters common between a list of words (including duplicates)"""
        if not words:
            return

        # O(n^2)
        words = [self._get_char_counts(word) for word in words]

        # O(nm), set intersection
        common = words[0].keys()
        for other in words[1:]:
            common &= other.keys()

        # O(nm), number of common characters across the number of words
        result = []
        for c in common:
            result += [c] * min(count[c] for count in words)

        return result