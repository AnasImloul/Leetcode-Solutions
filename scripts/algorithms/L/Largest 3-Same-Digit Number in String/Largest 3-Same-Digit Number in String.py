class Solution:
    def largestGoodInteger(self, n: str) -> str:
        return max(n[i-2:i+1] if n[i] == n[i - 1] == n[i - 2] else "" for i in range(2, len(n)))
