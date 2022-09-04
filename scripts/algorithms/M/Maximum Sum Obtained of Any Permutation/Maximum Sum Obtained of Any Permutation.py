# Runtime: 6387 ms (Top 5.45%) | Memory: 65.4 MB (Top 5.45%)
import numpy as np
class Solution:
    def maxSumRangeQuery(self, nums, requests) -> int:
        idx_freq = np.zeros(len(nums), dtype=np.int64)
        for start, end in requests:
            idx_freq[start: end + 1] += 1
        idx_freq.sort()
        arr_nums = np.array(nums, dtype=np.int64)
        arr_nums.sort()
        return np.sum(idx_freq * arr_nums) % 1_000_000_007