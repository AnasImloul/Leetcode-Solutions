# Runtime: 1243 ms (Top 52.9%) | Memory: 16.52 MB (Top 32.4%)

class Solution:
    def getMinSwaps(self, num: str, k: int) -> int:
        num = list(num)
        orig = num.copy()
        
        for _ in range(k): 
            for i in reversed(range(len(num)-1)): 
                if num[i] < num[i+1]: 
                    ii = i+1 
                    while ii < len(num) and num[i] < num[ii]: ii += 1
                    num[i], num[ii-1] = num[ii-1], num[i]
                    lo, hi = i+1, len(num)-1
                    while lo < hi: 
                        num[lo], num[hi] = num[hi], num[lo]
                        lo += 1
                        hi -= 1
                    break 
        
        ans = 0
        for i in range(len(num)): 
            ii = i
            while orig[i] != num[i]: 
                ans += 1
                ii += 1
                num[i], num[ii] = num[ii], num[i]
        return ans 