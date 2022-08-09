class Solution:
    def mostWordsFound(self, ss: List[str]) -> int:
        return max(s.count(" ") for s in ss) + 1
