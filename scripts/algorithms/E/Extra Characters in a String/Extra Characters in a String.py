# Runtime: 201 ms (Top 83.2%) | Memory: 16.38 MB (Top 79.3%)

class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        max_val = len(s) + 1
        dp = [max_val] * (len(s) + 1)
        dp[0] = 0 
        dictionary_set = set(dictionary)

        for i in range(1, len(s) + 1):
            dp[i] = dp[i - 1] + 1

            for l in range(1, i + 1): 
                if s[i-l:i] in dictionary_set:
                    dp[i] = min(dp[i], dp[i-l])
                    
        return dp[-1]