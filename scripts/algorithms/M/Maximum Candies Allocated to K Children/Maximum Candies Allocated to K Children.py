def canSplit(candies, mid, k):
    split = 0
    for i in candies:
        split += i//mid
    if split >= k:
        return True
    else:
        return False
    
class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        end = sum(candies)//k
        start = 1
        ans = 0
        while start <= end:
            mid = (start + end)//2
            if canSplit(candies, mid, k):
                start = mid + 1
                ans = mid
            else:
                end = mid - 1
        return ans
        
