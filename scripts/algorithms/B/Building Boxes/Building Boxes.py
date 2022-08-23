# Runtime: 68 ms (Top 24.24%) | Memory: 13.9 MB (Top 54.55%)
class Solution:
    def minimumBoxes(self, n: int) -> int:
        r = 0
        while (n_upper := r*(r+1)*(r+2)//6) < n:
            r += 1
        m = r*(r+1)//2
        for i in range(r, 0, -1):
            if (n_upper - i) < n:
                break
            n_upper -= i
            m -= 1
        return m