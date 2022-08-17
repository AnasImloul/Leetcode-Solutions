class Solution:
    def minimumLength(self, s: str) -> int:
        while(len(s)>1 and s[0]==s[-1]):
            s=s.strip(s[0])
        else:
            return len(s)
