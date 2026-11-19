# Runtime: 19 ms (Top 87.88%) | Memory: 20.70 MB (Top 90.91%)

sqs = [k*k for k in range (1,101)]

class Solution:
    def maximumSum(self, nums: List[int]) -> int:

        nums = [0]+nums
        n = len(nums)
        ans = max(nums[n//4:])          # <-- note above

        for i in range(1, n//4+1):      # <-- note above
            sm = 0
            for sq in sqs:
                if sq*i >= n: break
                sm+= nums[sq*i]
            ans = max(ans, sm)

        return ans
