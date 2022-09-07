# Runtime: 67 ms (Top 31.53%) | Memory: 13.9 MB (Top 60.59%)
class Solution:
    def maxScore(self, s: str) -> int:
        m0=0
        m1=0
        for i in s:
            if i=="0":
                m0+=1
            else:
                m1+=1
        if m0==0 or m1==0:
            return max(m0-1,m1-1)
        l=len(s)
        i=0
        max_=0
        c0=0
        c1=m1
        idx=-1
        while i <l:
            if s[i]=="0":
                c0+=1
            else:
                c1-=1
            if max_<c1+c0:
                max_=c1+c0
                idx=i
            max_=max(max_,c1+c0)
            i+=1
        if idx==l-1:
            return max_-1
        return max_
