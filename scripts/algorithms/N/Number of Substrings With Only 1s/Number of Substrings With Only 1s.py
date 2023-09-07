# Runtime: 46 ms (Top 40.6%) | Memory: 14.50 MB (Top 56.2%)

class Solution(object):
    def numSub(self, s):
        res, currsum = 0,0
        for digit in s:
            if digit == '0':
                currsum = 0
            else:
                currsum += 1 
                res+=currsum 
        return res % (10**9+7)