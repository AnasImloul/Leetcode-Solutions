class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
       v, c, l = [], 0, len(rocks)
        for i in range(l):
            p = capacity[i]-rocks[i]
            if(p>0):
                v.append(p)
            else: c += 1
        v.sort()
        k=0
        while(additionalRocks>0 and k<len(v)):
            if(v[k]<=additionalRocks):
                c += 1
                additionalRocks -= v[k]
            k += 1
        return c
