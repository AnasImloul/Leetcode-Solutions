# Runtime: 111 ms (Top 32.35%) | Memory: 13.9 MB (Top 33.68%)
class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        i = 0
        while i < len(words) - 1:
            if sorted(words[i]) == sorted(words[i + 1]):
                words.remove(words[i + 1])
                continue
            i += 1
        return words