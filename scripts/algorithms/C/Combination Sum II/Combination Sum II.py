# Runtime: 204 ms (Top 15.17%) | Memory: 14.1 MB (Top 23.77%)
class Solution(object):
    def combinationSum2(self, candidates, target):
        res = []
        def dfs(nums,summ,curr):
            if summ>=target:
                if summ == target:
                    res.append(curr)
                return
            for i in range(len(nums)):
                if i !=0 and nums[i]==nums[i-1]:
                    continue
                dfs(nums[i+1:],summ+nums[i],curr+[nums[i]])
        dfs(sorted(candidates),0,[])
        return res