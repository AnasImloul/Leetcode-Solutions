# Runtime: 612 ms (Top 5.26%) | Memory: 77.10 MB (Top 5.26%)

class Solution:
    def longestEqualSubarray(self, nums: List[int], k: int) -> int:
        indices = defaultdict(deque)
        ans = 0

        for i, x in enumerate(nums):
            indices[x].append(i)

            while indices[x][-1] - indices[x][0] + 1 > len(indices[x]) + k:
                indices[x].popleft()

            ans = max(ans, len(indices[x]))

        return ans
