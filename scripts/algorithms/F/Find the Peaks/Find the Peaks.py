# Runtime: 1 ms (Top 51.27%) | Memory: 19.10 MB (Top 85.44%)

class Solution:
    def findPeaks(self, a: List[int]) -> List[int]:
        res = []
        for i in range(1,len(a)-1):
            if a[i]>a[i-1] and a[i]>a[i+1]:
                res.append(i)
        return res
