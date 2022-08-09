class Solution:
    def maxSumAfterPartitioning(self, nums: List[int], k: int) -> int:
        def get_max(start, end):
            return max(nums[start:end + 1]) * (end - start + 1)

        def dfs(start):
            if start == N: # base case, so in tabulation we go [N - 1]...[0], as [N] = 0
                return 0
            
            maxi = float(-inf)
			# you partition at every position up to start + k and repeat the same process for the next partition
			# e.g. 1 9 3, k = 2
			# 1|9|3 => with max in each partition: 1|9|3 = 13
			# 1|9 3 => with max in each partition: 1|9 9 = 19
			# 1 9|3 => with max in each partition: 9 9|3 = 21
			# get max_in_partition(start,end) + give_me_max_for_array(previous_partition_end + 1, N)
			# rec.relation = max(max_sum_in_partition[start, end] + dfs(end + 1)))
            for end in range(start, min(N, start + k)):
                maxi = max(maxi, get_max(start, end) + dfs(end + 1))
            return maxi
        
        N = len(nums)
        return dfs(0)
