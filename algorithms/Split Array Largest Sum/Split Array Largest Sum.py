class Solution:
    def splitArray(self, nums: List[int], m: int) -> int:
        lo, hi = max(nums), sum(nums)
        while lo < hi:
            mid = (lo+hi)//2
            tot, cnt = 0, 1
            for num in nums:
                if tot+num<=mid: 
                    tot += num
                else:
                    tot = num
                    cnt += 1
            if cnt>m: lo = mid+1
            else: hi = mid
        return hi
