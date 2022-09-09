# Runtime: 3791 ms (Top 5.08%) | Memory: 15.3 MB (Top 74.05%)
class Solution:
    def smallestRangeII(self, lis: List[int], k: int) -> int:
        lis.sort()
        ans = lis[-1]-lis[0]
        for i in range(1,len(lis)):
            l = lis[:i]
            r = lis[i:]
            mini = min(l[0]+k,r[0]-k)
            maxi = max(l[-1]+k, r[-1]-k)
            ans = min(ans, maxi-mini)
        return ans

    ```