class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        beg, end = 0, 65535
        
        while beg <= end:
            mid = (beg+end)//2
            if mid*mid == num:
                return True
            elif mid*mid < num:
                beg =  mid+1
            else:
                end = mid-1
        return False
