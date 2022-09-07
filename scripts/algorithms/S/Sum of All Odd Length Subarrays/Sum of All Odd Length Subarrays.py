# Runtime: 68 ms (Top 74.29%) | Memory: 13.9 MB (Top 63.03%)
class Solution:
    def sumOddLengthSubarrays(self, arr: List[int]) -> int:
        n = len(arr)
        ans = 0
        for i in range(n):
            total = (i+1) * (n-1-i+1)
            ans = ans + (total//2 + total%2) * arr[i]
        return ans