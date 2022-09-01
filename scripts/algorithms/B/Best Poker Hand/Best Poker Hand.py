# Runtime: 38 ms (Top 59.18%) | Memory: 13.9 MB (Top 14.06%)
class Solution:
    def bestHand(self, ranks: List[int], suits: List[str]) -> str:
        s={}
        for i in suits:
            if i in s:
                s[i]+=1
                if s[i]==5:
                    return 'Flush'
            else:
                s[i]=1
        r={}
        max_ = 0
        for i in ranks:
            if i in r:
                r[i]+=1
                max_=max(max_,r[i])
            else:
                r[i]=1
        if max_>=3:
            return "Three of a Kind"
        elif max_==2:
            return "Pair"
        else:
            return "High Card"