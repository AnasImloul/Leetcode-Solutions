# Runtime: 38 ms (Top 76.97%) | Memory: 13.8 MB (Top 98.42%)

class Solution(object):
    def summaryRanges(self, nums):

        if len(nums) == 0:
            return []

        l, r = 0, 0
        res = []

        while l<=r and r <= len(nums):

            if r == 0:
                r+=1

            while r < len(nums) and r>0 and nums[r-1] == nums[r]-1:
                r+=1

            if r-1 == l:
                    res.append(str(nums[r-1]))
            else:
                res.append(str(nums[l]) + '->' + str(nums[r-1]))

            l=r
            r+=1

        return res