# Runtime: 1405 ms (Top 5.77%) | Memory: 15.2 MB (Top 23.08%)
class Solution:
    def minSwaps(self, grid) -> int:
        n = len(grid)
        max_right = [-1] * n
        for r, row in enumerate(grid):
            for c in range(n - 1, -1, -1):
                if row[c] == 1:
                    max_right[r] = c
                    break
        if all(v <= i for i, v in enumerate(sorted(max_right))):
            swaps = 0
            i = 0
            while i < n:
                while i < n and max_right[i] <= i:
                    i += 1
                if i == n:
                    break
                j = i
                while j < n and max_right[j] > i:
                    j += 1
                swaps += j - i
                max_right[i], max_right[i + 1: j + 1] = (max_right[j],
                                                         max_right[i: j])
                i += 1
            return swaps
        return -1