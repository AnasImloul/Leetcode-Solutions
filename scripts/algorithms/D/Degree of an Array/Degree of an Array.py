# Runtime: 274 ms (Top 86.33%) | Memory: 16.5 MB (Top 16.14%)
class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        degree = {num: [] for num in nums}

        for i, num in enumerate(nums):
            degree[num].append(i)

        indices= sorted(degree.values(), key = lambda x: len(x), reverse = True)
        max_len = len(indices[0])
        min_subarray = len(nums)
        # There could be multiple number with same number of repetition
        for index in indices:
            if len(index) != max_len:
                break
            min_subarray = min(min_subarray, index[-1] - index[0])
        return min_subarray + 1