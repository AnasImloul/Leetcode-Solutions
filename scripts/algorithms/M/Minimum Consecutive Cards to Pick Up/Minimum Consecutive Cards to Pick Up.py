class Solution:
    def minimumCardPickup(self, cards: List[int]) -> int:
        d={}
        x=[]
        for i in range(len(cards)):
            if cards[i] not in d:
                d[cards[i]]=i
            else:
                x.append(i-d[cards[i]])
                d[cards[i]]=i
        if len(x)<=0:
            return -1
        return min(x)+1
