class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k==0 or k==1:
            return 0
        p=1
        ini=0
        fin=0
        n=len(nums)
        c=0
        while fin<n:
            p=p*nums[fin]
            while p>=k :
                p=p//nums[ini]
                ini+=1

            n1=fin-ini+1
            c+=n1
            fin+=1
        return c
