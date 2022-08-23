# Runtime: 48 ms (Top 54.68%) | Memory: 13.9 MB (Top 56.46%)
class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        return len(set(sentence)) == 26