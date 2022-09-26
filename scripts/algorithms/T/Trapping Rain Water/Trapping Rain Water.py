# Runtime: 254 ms (Top 43.79%) | Memory: 16.1 MB (Top 46.67%)
class Solution:
    def trap(self, a: List[int]) -> int:
        l=0
        r=len(a)-1
        maxl=0
        maxr=0
        res=0

        while (l<=r):
            if a[l]<=a[r]:
                if a[l]>=maxl: maxl=a[l] #update maxl if a[l] is >=
                else: res+=maxl-a[l] #adding captured water when maxl>a[l]
                l+=1
            else:
                if a[r]>=maxr: maxr=a[r]
                else: res+=maxr-a[r]
                r-=1
        return res
