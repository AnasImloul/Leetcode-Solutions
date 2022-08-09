class Solution:
    def generateTheString(self, n: int) -> str:
        alpha = "abcdefghijklmnopqrstuvwxyz"
        res=""
        while n>0:
            curr, alpha = alpha[0], alpha[1:]
            if n%2:
                res += curr*n
                n-=n
            else: 
                res += curr*(n-1)
                n-=n-1
        return res