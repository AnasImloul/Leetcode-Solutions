class Solution:
    def baseNeg2(self, n: int) -> str:
        ans = ""
        while n != 0:
            if n%-2 != 0 :
                ans = '1' + ans
                n = (n-1)//-2
            else:
                ans = '0' + ans
                n = n//-2
        return ans if ans !="" else '0'
