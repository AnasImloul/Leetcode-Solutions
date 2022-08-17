class Solution:
    def targetIndices(self, nums, target):
        ans = []
        for i,num in enumerate(sorted(nums)):
            if num == target: ans.append(i)
        return ans
