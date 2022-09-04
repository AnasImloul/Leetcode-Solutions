# Runtime: 489 ms (Top 6.14%) | Memory: 14.1 MB (Top 72.07%)
class Solution:
    def magicalString(self, n: int) -> int:
        queue, ans, i = deque([2]), 1, 1

        while i <= n - 2:
            m = queue.popleft()
            ans += (m == 1)
            queue.extend([1 + (i % 2 == 0)] * m)
            i += 1

        return ans