class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        n=len(part)
        while part in s:
            i=s.index(part)
            s=s[:i]+s[i+n:]
        return s
