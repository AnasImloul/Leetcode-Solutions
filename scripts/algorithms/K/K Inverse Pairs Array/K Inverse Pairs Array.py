// Runtime: 185 ms (Top 92.81%) | Memory: 17.30 MB (Top 67.63%)

class Solution:
                        # A very good description of the dp solution is at
                        # https://leetcode.com/problems/k-inverse-pairs-array/solution/ 
                        # The code below uses two 1D arrays--dp and tmp--instead if a 
                        # 2D array. tmp replaces dp after each i-iteration.
    def kInversePairs(self, n: int, k: int) -> int:
        dp, mod = [1]+[0] * k, 1000000007
        
        for i in range(n):
            tmp, sm = [], 0
            for j in range(k + 1):
                sm+= dp[j]
                if j-i >= 1: sm-= dp[j-i-1]
                sm%= mod
                tmp.append(sm)
            dp = tmp
            #print(dp)       # <-- uncomment this line to get a sense of dp from the print output
			                 #     try n = 6, k = 4; your answer should be 49.
        return dp[k]