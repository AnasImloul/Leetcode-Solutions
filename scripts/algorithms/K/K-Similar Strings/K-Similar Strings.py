class Solution:
    def kSimilarity(self, s1: str, s2: str) -> int:
        n = len(s1)
        
        def helper(i, curr, dp):
            if curr == s2:
                return 0
            
            if curr not in dp[i]:
                if curr[i] == s2[i]:
                    dp[i][curr] = helper(i+1, curr, dp)
                else:
                    temp = sys.maxsize
                    for j in range(i+1, n):
                        if curr[j] == s2[i]:
                            temp = min(temp, 1+helper(i+1, curr[:i]+curr[j]+curr[i+1:j]+curr[i]+curr[j+1:], dp))

                    dp[i][curr] = temp
            return dp[i][curr]
        
        dp = [{} for _ in range(n)]
        return helper(0, s1, dp)
