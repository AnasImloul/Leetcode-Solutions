class Solution:
    def sumSubarrayMins(self, arr: List[int]) -> int:
        n = len(arr)
        small_before = [-1]*n
        stack = []
        for i in range(n):
            while stack and arr[stack[-1]] >= arr[i]:
                stack.pop()
            if stack:small_before[i] = stack[-1]
            stack.append(i)
        best = [0]*(n+1)
        ans = 0
        for i in range(n):
            best[i] = best[small_before[i]] + (i - small_before[i])*arr[i]
            ans += best[i]
        return ans%1000000007