class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        count=0
        for i in words:
            if (s[:len(i)]==i):
                count+=1
        return count
