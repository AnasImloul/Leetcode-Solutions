class Solution:
    def stoneGameVI(self, alice: List[int], bob: List[int]) -> int:
        t=list(zip(alice,bob))
        t=sorted(t,key=lambda x: sum(x),reverse=True)
        al=sum([i[0] for i in t[::2]])
        bb=sum([i[1] for i in t[1::2]])
        if al>bb:
            return 1
        elif al<bb:
            return -1
        return 0
