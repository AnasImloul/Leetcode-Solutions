# Runtime: 1132 ms (Top 16.52%) | Memory: 15.2 MB (Top 81.46%)
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        """
        # Memoization + DFS Solution
        # TLE as we have as much as n decisions depending on nums[i] which could be
        # 10^5 as an uppercase according to problem constraints
        # better off with a greedy approach

        cache = {} # i : bool

        def dfs(i):
            if i == len(nums) -1:
                return True
            if nums[i] == 0:
                return False
            if i in cache:
                return cache[i]
            for j in range(1, nums[i] + 1):
                res = dfs(i + j)
                if res:
                    cache[i] = True
                    return cache[i]
            cache[i] = False
            return cache[i]

        return dfs(0)
        """
        # Greedy Solution
        # Key with greedy is to find a local and gobal optimum
        # here we find the furthest distance we can travel with each index

        # futhest index reachable
        reachable = 0

        # iterate through all indexes and if the current index is futher than what we can travel return fasle
        for i in range(len(nums)):
            if i > reachable:
                return False

            reachable = max(reachable, nums[i] + i)
            # if the futherest distance we can jump to is greater or equal than the last index break
            if reachable >= len(nums) - 1:
                break

        return True