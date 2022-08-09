class Solution:
    def firstUniqChar(self, s: str) -> int:
        ls=[]
        for i in range(len(s)):
            x=s.count(s[i])
            if x==1:
                return i
        return -1
