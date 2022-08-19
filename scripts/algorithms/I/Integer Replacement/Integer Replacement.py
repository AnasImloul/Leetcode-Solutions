# Runtime: 42 ms (Top 77.23%) | Memory: 14 MB (Top 29.19%)

class Solution:
    def integerReplacement(self, n: int) -> int:
        dp = {}
        def dfs(num):
            if num == 1:
                return 0

            if num in dp:
                return dp[num]

            # if num is even, we have only one option -> n / 2
            even = odd = 0
            if num % 2 == 0:
                even = 1 + dfs(num // 2)
            else:
                # if num is odd, we have two option, either we increment the num or decrement the num
                odd1 = 1 + dfs(num - 1)
                odd2 = 1 + dfs(num + 1)
                # take the min of both operation
                odd = min(odd1, odd2)

            dp[num] = even + odd
            return dp[num]

        return dfs(n)