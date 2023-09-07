# Runtime: 733 ms (Top 62.5%) | Memory: 31.64 MB (Top 85.1%)

from itertools import accumulate 

class Solution(object):
    def getSumAbsoluteDifferences(self, nums):
        total, n = sum(nums), len(nums) #for i, ri in zip(nums, reversed(nums)): pref.append(pref[-1] + i)
        return [(((i+1) * num) - pref) + ((total-pref) - ((n-i-1) * num)) for (i, num), pref in zip(enumerate(nums), list(accumulate(nums)))]
        