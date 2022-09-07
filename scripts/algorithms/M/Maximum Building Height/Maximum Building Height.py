# Runtime: 4560 ms (Top 6.25%) | Memory: 52.1 MB (Top 56.25%)
class Solution:
    def maxBuilding(self, n: int, restrictions: List[List[int]]) -> int:
        arr = restrictions
        arr.extend([[1,0],[n,n-1]])
        arr.sort()
        n = len(arr)
        for i in range(1,n):
            arr[i][1] = min(arr[i][1], arr[i-1][1]+arr[i][0]-arr[i-1][0])
        for i in range(n-2,-1,-1):
            arr[i][1] = min(arr[i][1], arr[i+1][1]+arr[i+1][0]-arr[i][0])
        res = 0
        for i in range(1,n):
            #position where height can be the highest between arr[i-1][0] and arr[i][0]
            k = (arr[i][1]-arr[i-1][1]+arr[i][0]+arr[i-1][0])//2
            res = max(res, arr[i-1][1]+k-arr[i-1][0])
        return res