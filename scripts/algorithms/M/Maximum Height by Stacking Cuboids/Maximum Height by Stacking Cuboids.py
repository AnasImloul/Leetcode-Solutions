# Runtime: 199 ms (Top 36.11%) | Memory: 13.8 MB (Top 87.22%)

class Solution:
    def maxHeight(self, cuboids: List[List[int]]) -> int:
        dp=[0]*len(cuboids)
        max_value=0
        for i in range(len(cuboids)):
            cuboids[i].sort()
        cuboids.sort()
        for i in range(len(cuboids)):
            dp[i]=cuboids[i][2]
            for j in range(i):
                if cuboids[i][0]>=cuboids[j][0] and cuboids[i][1]>=cuboids[j][1] and cuboids[i][2]>=cuboids[j][2]:
                    dp[i]=max(dp[i],dp[j]+cuboids[i][2])
            if dp[i]>max_value:
                max_value=dp[i]
        return max_value