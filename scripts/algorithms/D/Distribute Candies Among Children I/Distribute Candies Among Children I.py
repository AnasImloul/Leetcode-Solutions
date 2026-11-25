# Runtime: 15 ms (Top 57.71%) | Memory: 19.00 MB (Top 90.51%)

class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        count = 0

        for i in range(min(n, limit) + 1):
            for j in range(min(n - i, limit) + 1):

                k = n - i - j
                if 0 <= k <= limit:
                    count += 1

        return count
