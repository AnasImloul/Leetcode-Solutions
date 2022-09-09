# Runtime: 3346 ms (Top 89.52%) | Memory: 46.9 MB (Top 30.64%)
class Solution:
    def waysToPartition(self, nums: List[int], k: int) -> int:
        prefix_sums = list(accumulate(nums))
        total_sum = prefix_sums[-1]
        best = 0
        if total_sum % 2 == 0:
            best = prefix_sums[:-1].count(total_sum // 2) # If no change

        after_counts = Counter(total_sum - 2 * prefix_sum
                               for prefix_sum in prefix_sums[:-1])
        before_counts = Counter()

        best = max(best, after_counts[k - nums[0]]) # If we change first num

        for prefix, x in zip(prefix_sums, nums[1:]):
            gap = total_sum - 2 * prefix
            after_counts[gap] -= 1
            before_counts[gap] += 1

            best = max(best, after_counts[k - x] + before_counts[x - k])

        return best