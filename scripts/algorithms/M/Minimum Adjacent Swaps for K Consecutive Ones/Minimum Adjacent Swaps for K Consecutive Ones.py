class Solution:
    def minMoves(self, nums: List[int], k: int) -> int:
        p = [i for i, v in enumerate(nums) if v == 1]
        # p[i]: the position of i-th 1
        n = len(p)
        presum = [0]*(n+1)
        # presum[i]: sum(p[0]...p[i-1])
        for i in range(n):
            presum[i+1] = presum[i]+p[i]

        res = inf

        # sliding window
        if k % 2 == 1:
            # if odd
            radius = (k-1)//2
            for i in range(radius, n-radius):
                # i-radius ... i ... i+radius
                # move radius to i
                # i+1, ..., i+radius
                right = presum[i+radius+1]-presum[i+1]
                # i-radius, ..., i-1
                left = presum[i]-presum[i-radius]
                res = min(res, right-left)
            return res-radius*(radius+1)
        else:
            # even
            radius = (k-2)//2
            for i in range(radius, n-radius-1):
                # i-radius ... i i+1 ... i+radius+1
                # move radius to i (moving to i+1 is also OK)
                # i+1, ..., i+radius+1
                right = presum[i+radius+2]-presum[i+1]
                # i-radius, ..., i-1
                left = presum[i]-presum[i-radius]
                res = min(res, right-left-p[i])
            return res-radius*(radius+1)-(radius+1)
