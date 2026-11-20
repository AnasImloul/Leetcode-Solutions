# Runtime: 1 ms (Top 41.90%) | Memory: 19.10 MB (Top 76.68%)

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:

                                                #  Example: nums = [3,1,5,4,2]   k=2
        s = cnt = 0                             #           goal = (1<<3)-2 = 6 = '110'
        goal = (1<<(k+1)) - 2

        while nums:                             #   num    s    cnt
                                                #   \u2013\u2013\u2013   \u2013\u2013\u2013   \u2013\u2013\u2013 
            cnt+= 1                             #    2    100    1
            if (num:=nums.pop()) <= k:          #    4    100    2
                s|= (1<<num)                    #    5    100    3
                                                #    1    110    4 <--return 4
            if  s == goal: return cnt
