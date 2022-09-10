# Runtime: 136 ms (Top 31.20%) | Memory: 14.2 MB (Top 62.53%)
class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) == 1:
            return [[nums[0]]]

        res = self.permuteUnique(nums[1:])

        for i in range(len(res)-1, -1 , -1):
            j = 0
            while j < len(res[i]):
                if res[i][j] == nums[0]: #to account for repeated nums
                    break
                lst = res[i][:]
                lst.insert(j, nums[0])
                res.append(lst)
                j += 1

            res[i].insert(j,nums[0])

        return res