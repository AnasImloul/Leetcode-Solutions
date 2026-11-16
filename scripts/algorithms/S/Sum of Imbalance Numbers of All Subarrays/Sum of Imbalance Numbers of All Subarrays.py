# Runtime: 3 ms (Top 100.00%) | Memory: 19.20 MB (Top 75.00%)

class Solution:
    def sumImbalanceNumbers(self, A: List[int]) -> int:
        n = len(A)

        left = [-1] * n
        last = [-1] * (n + 2)
        for i in range(n):
            left[i] = last[A[i] + 1]
            last[A[i]] = i

        right = [n] * n
        last = [n] * (n + 2)
        for i in range(n - 1, -1, -1):
            right[i] = min(last[A[i]], last[A[i] + 1])
            last[A[i]] = i

        ans = 0
        for i in range(n):
            ans += (i - left[i]) * (right[i] - i)
        return ans - n * (n + 1) // 2
