# Runtime: 1794 ms (Top 11.20%) | Memory: 13.8 MB (Top 87.90%)
class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        count = 0
        for i in range(len(arr)):
            for j in range(i+1,len(arr)):
                for k in range(j+1,len(arr)):
                    if abs(arr[i]-arr[j])<=a and abs(arr[j]-arr[k])<=b and abs(arr[k]-arr[i])<=c:
                        count+=1
        return count