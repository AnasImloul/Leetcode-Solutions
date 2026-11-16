# Runtime: 1 ms (Top 45.02%) | Memory: 19.00 MB (Top 97.78%)

import bisect
class Solution:
    def reverse(self, x: int) -> int:

        flag = 0
        if x<0:
            x = abs(x)
            flag = 1
            
        l = [i for i in str(x)]
        l.reverse()
        
        ret = ''.join(l)
        ret = int(ret)
        
        if flag == 1:
            ret = ret*-1
            
        if ((ret >= (-(2**31))) and (ret<=((2**31)-1))):
            return ret
        else:
            return 0
