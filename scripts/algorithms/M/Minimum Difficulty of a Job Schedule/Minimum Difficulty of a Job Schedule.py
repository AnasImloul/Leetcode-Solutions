class Solution:
    def solve(self, nums, index, d):
        if index == len(nums) or d == 1:
            #print(max(nums[index:]))
            return max(nums[index:])
        ans = float("inf")
        for i in range(index, len(nums)-d+1):
            curr = max(nums[index:i+1]) + self.solve(nums, i+1, d-1)
            ans = min(ans, curr)
        return ans
    
    def minDifficulty(self, jobDifficulty: List[int], d: int) -> int:
        ans = self.solve(jobDifficulty, 0, d)
        if ans == float("inf"):
            return -1
        else:
            return ans
