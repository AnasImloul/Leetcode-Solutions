# Runtime: 34 ms (Top 88.32%) | Memory: 13.8 MB (Top 97.42%)
class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        idx=word.find(ch)
        if idx:
            return word[:idx+1][::-1]+ word[idx+1:]
        return word