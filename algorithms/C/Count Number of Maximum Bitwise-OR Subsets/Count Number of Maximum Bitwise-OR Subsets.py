class Solution:
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        
        def dfs(i,val):
            if maxBit == val : return 1<<(len(nums)-i)
            if i == len(nums): return 0
            return dfs(i+1,val|nums[i]) + dfs(i+1,val)
        maxBit = 0
        for i in nums: maxBit |= i
        return dfs(0,0)
