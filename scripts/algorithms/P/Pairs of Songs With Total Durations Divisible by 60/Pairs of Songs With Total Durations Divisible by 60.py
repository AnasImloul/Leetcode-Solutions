// Runtime: 235 ms (Top 92.55%) | Memory: 21.60 MB (Top 5.78%)

class Solution:
    def numPairsDivisibleBy60(self, time: List[int]) -> int:
        res  , count  = 0,  [0] * 60
        for one in range(len(time)):
            index = time[one] % 60
            res += count[(60 - index)%60] # %60 is for index==0
            count[index] += 1
        return res
