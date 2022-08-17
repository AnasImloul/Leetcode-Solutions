from math import log
class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        if bound == 0:
            return []
        maxi = int(log(bound,max(x,2))) +1
        maxj = int(log(bound,max(y,2))) +1
        L = set()
        for i in range(maxi):
            for j in range(maxj):
                if (t:=x**i +y**j) <= bound:
                    L.add(t)
                else:
                    break
        return list(L)
