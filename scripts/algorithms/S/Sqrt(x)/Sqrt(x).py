class Solution:
    def mySqrt(self, x: int) -> int:
        beg =0
        end =x
        while beg <=end:
            mid = (beg+end)//2
            sqr = mid*mid
            if sqr == x:
                return mid
            elif sqr < x:
                beg = mid+1
            else:
                end = mid-1
        return end
        
