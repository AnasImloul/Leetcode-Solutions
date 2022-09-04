# Runtime: 1276 ms (Top 58.39%) | Memory: 15.2 MB (Top 22.81%)
from collections import defaultdict

class Solution:
    def smallestTrimmedNumbers(self, nums: List[str], queries: List[List[int]]) -> List[int]:
        sl = len(nums[0])
        len_to_sorted = defaultdict(list)
        ans = [0] * len(queries)

        for i, (k_smallest, trim_len) in enumerate(queries):
            if trim_len not in len_to_sorted:
                # have to trim
                for ni, num in enumerate(nums):
                    len_to_sorted[trim_len].append( (int(num[sl - trim_len:]), ni) )

                len_to_sorted[trim_len] = sorted(len_to_sorted[trim_len])
            ans[i] = len_to_sorted[trim_len][k_smallest -1][1]

        return ans