# Runtime: 1522 ms (Top 17.46%) | Memory: 14.2 MB (Top 76.15%)
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        req={}
        for i in words:
            req[i]=1+req.get(i,0)
        l=0
        r=len(words)*len(words[0])
        ans=[]

        while r<len(s)+1:
            i=0
            curr={}
            left, right= l, l+len(words[0])
            while right<l+len(words)*len(words[0])+1:
                x=s[left:right]
                # print(x)
                if x in req.keys():
                    curr[x]= 1+ curr.get(x,0)
                left=right
                right=right+len(words[0])
            if req==curr:
                ans.append(l)
            l=l+1
            r=r+1
        return ans