# Runtime: 2 ms (Top 41.92%) | Memory: 19.30 MB (Top 38.70%)

class Solution:
    def findWordsContaining(self, words: List[str], x: str) -> List[int]:
        res = []
        for i in range(len(words)):
            if x in words[i]:
                res.append(i)
        return res
