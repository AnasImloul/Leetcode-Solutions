class Solution:
    def makeGood(self, s: str) -> str:
        while True:
            for i in range(len(s)-1):
                if s[i].lower() == s[i+1].lower() and (s[i].islower() and s[i+1].isupper() or s[i].isupper() and s[i+1].islower()):
                    s = s[:i]+s[i+2:]
                    break
            else:
                break
        return s