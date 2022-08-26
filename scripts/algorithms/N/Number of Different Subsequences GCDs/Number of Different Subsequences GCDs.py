// Runtime: 5748 ms (Top 75.00%) | Memory: 34.4 MB (Top 21.43%)
import math

class Solution:
    def countDifferentSubsequenceGCDs(self, nums: List[int]) -> int:
        max_n = max(nums) + 1
        seen = set(nums)

        ans = 0
        for k in range(1, max_n): # iterate candidate k
            gcd = 0
            for multiple in range(k, max_n, k): # compute gcd of all array multiples of k
                if multiple in seen:
                    gcd = math.gcd(gcd, multiple)
            if gcd == k: # check the candidate
                ans += 1
        return ans