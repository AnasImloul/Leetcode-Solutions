# Runtime: 782 ms (Top 50.50%) | Memory: 18.9 MB (Top 42.22%)

class Solution(object):
    def numRollsToTarget(self, n, k, target):
        """
        :type n: int
        :type k: int
        :type target: int
        :rtype: int
        """

        mem = {}

        def dfs(i,currSum):

            if currSum > target:
                return 0

            if i == n:
                if currSum == target:
                    return 1
                return 0

            if (i,currSum) in mem:
                return mem[(i,currSum)]

            ans = 0
            for dicenumber in range(1,k+1):
                ans += dfs(i+1,currSum+dicenumber)

            mem[(i,currSum)] = ans

            return mem[(i,currSum)]

        return dfs(0,0) % (10**9 + 7)
