# Runtime: 1388 ms (Top 11.51%) | Memory: 17.1 MB (Top 35.27%)
class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def calc(m):#function calculate no of days for given weight
            c,s=0,0
            for i in weights:
                if i+s>m:
                    c+=1
                    s=0
                s+=i
            if s>0:
                c+=1
            return c
        left,right=max(weights),sum(weights)
        while left <=right:
            mid = (left+right)//2
            if calc(mid) > days:
                left = mid+1
            else :
                right = mid -1
        return left