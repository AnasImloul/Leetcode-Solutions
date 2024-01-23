// Runtime: 52 ms (Top 87.09%) | Memory: 16.80 MB (Top 65.44%)

class Solution:
	def minCostClimbingStairs(self, cost: List[int]) -> int:
		cur = 0 
		dp0 = cost[0]
		if len(cost) >= 2:
			dp1 = cost[1]

		for i in range(2, len(cost)):
			cur = cost[i] + min(dp0, dp1)
			dp0 = dp1
			dp1 = cur

		return min(dp0, dp1)
