# Runtime: 72 ms (Top 19.91%) | Memory: 32.20 MB (Top 99.53%)

class Solution:
    def checkArray(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        pref = [0]*(n+1)
        ac = 0
        for i in range(0,n):
            ac-=pref[i]
            nums[i]-=ac

            if nums[i]<0:
                return False
            if i+k<=n:
                ac+=nums[i]
                pref[i+k]+=nums[i]
                nums[i] = 0
            elif nums[i]>0:
                return False

        return True
