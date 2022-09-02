# Runtime: 54 ms (Top 28.53%) | Memory: 13.9 MB (Top 25.25%)
class Solution:
    def nextGreaterElement(self, n: int) -> int:
        s=list(str(n))
        ind=-1
        for x in range(len(s)-1,0,-1):
            if s[x]>s[x-1]:
                ind=x-1
                break
        if ind==-1:
            return -1
        ind2=-1
        for x in range(len(s)-1,ind,-1):
            if s[x]>s[ind]:
                ind2=x
                break
        s[ind],s[ind2]=s[ind2],s[ind]
        s=s[:ind+1]+s[ind+1:][::-1]
        n1=int(''.join(s))
        if n==n1 or n1>(2**31-1):
            return -1
        else:
            return n1