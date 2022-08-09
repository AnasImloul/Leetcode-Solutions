class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        res=""
        count=0
        while len(res)<len(b)+len(a):
            count+=1
            res=a*count
            if b in res:
                return count
        return -1
