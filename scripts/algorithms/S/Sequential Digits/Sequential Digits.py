class Solution:
    def sequentialDigits(self, l: int, h: int) -> List[int]:
        q=[*"123456789"]
        a=[]
        for i in range(10):
            for j in range(i+1,10):
                o=int("".join(q[i:j]))
                if l<=o<=h:
                    a+=[o]
        return sorted(a)