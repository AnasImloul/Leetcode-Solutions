# Runtime: 165 ms (Top 74.37%) | Memory: 13.8 MB (Top 95.72%)
class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        def dfs(idx,curr,cnt,limit):
            if cnt == k:
                return True
            if curr ==limit:
                return dfs(0,0,cnt+1,limit)

            i = idx
            while i < len(nums):
                if visited[i] or nums[i]+curr > limit:
                    i += 1
                    continue
                visited[i] = True
                if dfs(i+1,curr+nums[i],cnt,limit):
                    return True
                visited[i] = False

                while i+1 < len(nums) and nums[i] == nums[i+1]: #pruning1
                    i += 1
                if curr == 0 or curr + nums[i] == limit: #pruning2
                    return False
                i += 1
            return False

        if len(nums) < k or sum(nums) % k:
            return False
        numSum = sum(nums)

        for i in range(len(nums)):
            if nums[i] > numSum//k:
                return False

        visited = [False]*len(nums)
        return dfs(0,0,0,numSum//k)