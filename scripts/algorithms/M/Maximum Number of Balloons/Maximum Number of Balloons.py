class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        d1={}
        for i in text:
            if i in d1:
                d1[i]+=1
            else:
                d1[i]=1
        d2={}
        for i in "balloon":
            if i in d2:
                d2[i]+=1
            else:
                d2[i]=1
        min_=10001
        for i in d2:
            if i in d1:
                min_=min(min_,d1[i]//d2[i])
            else:
                return 0
        return min_
