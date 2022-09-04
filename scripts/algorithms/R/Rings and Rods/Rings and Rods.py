# Runtime: 56 ms (Top 27.28%) | Memory: 13.8 MB (Top 63.52%)
class Solution:
    def countPoints(self, r: str) -> int:
        ans = 0
        for i in range(10):
            i = str(i)
            if 'R'+i in r and 'G'+i in r and 'B'+i in r:
                ans += 1
        return ans