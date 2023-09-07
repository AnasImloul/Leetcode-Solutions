# Runtime: 209 ms (Top 98.8%) | Memory: 16.64 MB (Top 51.7%)

class Solution:
    def subarraysDivByK(self, nums, k):
        n = len(nums)
        prefix_mod = 0
        result = 0

        # There are k mod groups 0...k-1.
        mod_groups = [0] * k
        mod_groups[0] = 1

        for num in nums:
            # Take modulo twice to avoid negative remainders.
            prefix_mod = (prefix_mod + num % k + k) % k
            # Add the count of subarrays that have the same remainder as the current
            # one to cancel out the remainders.
            result += mod_groups[prefix_mod]
            mod_groups[prefix_mod] += 1

        return result