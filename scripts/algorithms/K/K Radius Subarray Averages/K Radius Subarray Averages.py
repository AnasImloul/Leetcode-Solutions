# Runtime: 1318 ms (Top 77.1%) | Memory: 35.26 MB (Top 20.0%)

class Solution:
    def getAverages(self, nums: list[int], k: int) -> list[int]:

        n, diam = len(nums), 2*k+1
        if n < diam: return [-1]*n

        ans = [-1]*k

        arr = list(accumulate(nums, initial = 0))

        for i in range(n-diam+1):
            ans.append((arr[i+diam]-arr[i])//diam)

        return  ans + [-1]*k