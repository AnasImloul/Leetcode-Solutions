# Runtime: 2740 ms (Top 30.44%) | Memory: 19.5 MB (Top 65.22%)
class Solution(object):
    def countTexts(self, pressedKeys):
        """
        :type pressedKeys: str
        :rtype: int
        """
        dp = [1] + [0]*len(pressedKeys)
        mod = 10**9 + 7
        for i, n in enumerate(pressedKeys):
            dp[i+1] = dp[i]
            # check if is continous
            if i >= 1 and pressedKeys[i-1] == n:
                dp[i+1] += dp[i-1]
                dp[i+1] %= mod
                if i >= 2 and pressedKeys[i-2] == n:
                    dp[i+1] += dp[i-2]
                    dp[i+1] %= mod
                    # Special case for '7' and '9' that can have 4 characters combination
                    if i >= 3 and pressedKeys[i-3] == n and (n == "7" or n == "9"):
                        dp[i+1] += dp[i-3]
                        dp[i+1] %= mod
        return dp[-1]