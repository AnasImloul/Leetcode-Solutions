# Runtime: 1506 ms (Top 29.6%) | Memory: 34.22 MB (Top 74.0%)

class Solution:
    def minSumSquareDiff(self, nums1: List[int], nums2: List[int], k1: int, k2: int) -> int:
        n = len(nums1)
        k = k1+k2 # can combine k's because items can be turned negative
        diffs = sorted((abs(x - y) for x, y in zip(nums1, nums2)))
        
        # First binary search to find our new max for our diffs array
        l, r = 0, max(diffs)
        while l < r:
            mid = (l+r)//2
            
            # steps needed to reduce all nums greater than newMax
            steps = sum(max(0, num-mid) for num in diffs)
            
            if steps <= k:
                r = mid
            else:
                l = mid+1
                
        newMax = l
        k -= sum(max(0, num-newMax) for num in diffs) # remove used k

        # Second binary search to find first index to replace with max val
        l, r = 0, n-1
        while l < r:
            mid = (l+r)//2
            if diffs[mid] < newMax:
                l = mid+1
            else:
                r = mid

        # Replace items at index >= l with newMax
        diffs = diffs[:l]+[newMax]*(n-l)
        
        # Use remaining steps to reduce overall score
        for i in range(len(diffs)-1,-1,-1):
            if k == 0 or diffs[i] == 0: break
            diffs[i] -= 1
            k -= 1
            
        return sum(diff*diff for diff in diffs)