from collections import Counter
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        l='abcdefghijklmnopqrstuvwxyz'
        if len(p)>len(s):
            return []
        d={}
        for x in l:
            d[x]=0
        d1=dict(d)
        d2=dict(d)
        for x in range(len(p)):
            d1[s[x]]+=1
            d2[p[x]]+=1
        l1=[]
        if d1==d2:
            l1=[0]
        #print(d1)
        for x in range(len(p),len(s)):
            d1[s[x]]+=1
            d1[s[x-len(p)]]-=1
            if d1==d2:
                l1.append(x-len(p)+1)
        return l1
