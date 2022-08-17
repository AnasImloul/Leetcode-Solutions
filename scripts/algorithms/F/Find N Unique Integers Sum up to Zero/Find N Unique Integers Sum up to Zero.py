class Solution:
    def sumZero(self, n: int) -> List[int]:
        q,p=divmod(n,2)
        if p:
            return list(range(-q, q+1))
        else:
            return list(range(-q,0))+list(range(1,q+1))