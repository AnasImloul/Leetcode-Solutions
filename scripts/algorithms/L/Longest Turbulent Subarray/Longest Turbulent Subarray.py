# Runtime: 1152 ms (Top 13.10%) | Memory: 18.7 MB (Top 31.75%)
class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        def cmp(a,b):
            if a == b: return 0
            if a > b : return 1
            return -1

        n = len(arr)
        ans = 1
        prev = 0
        for i in range(1,n):
            c = cmp(arr[i-1],arr[i])
            if c == 0:
                # we shift prev to i
                prev = i
            elif i == n-1 or c * cmp(arr[i],arr[i+1]) != -1:
                ans = ans if ans > i - prev + 1 else i - prev + 1
                prev = i
        return ans