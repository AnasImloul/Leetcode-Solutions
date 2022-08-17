class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        a, b, c = sorted([a, b, c], reverse=True)
        ans = 0
        while a > 0 and b > 0:
            a -= 1
            b -= 1
            ans += 1
            a, b, c = sorted([a, b, c], reverse=True)
        return ans
