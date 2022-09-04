# Runtime: 39 ms (Top 86.68%) | Memory: 13.9 MB (Top 58.98%)
class Solution:
    def constructRectangle(self, area: int):
        y = Solution.mySqrt(area)
        for i in range(y, 0, -1):
            if not area%i:
                return [int(area/i), i]

    def mySqrt(x):
        if x == 0:
            return 0
        n = x
        count = 0
        while True:
            count += 1
            root = 0.5 * (n + (x / n))
            if abs(root - n) < 0.9:
                break
            n = root
        return int(root)