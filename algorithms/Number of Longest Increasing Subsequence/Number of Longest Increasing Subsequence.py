class Solution:
    def findNumberOfLIS(self, nums) -> int:
        cnt=[1 for _ in range(len(nums))]
        dp=[1 for _ in range(len(nums))]
        maximum=0
        maxLst=[]
        for i in range(len(nums)):
            for j in range(i):
                if nums[j]<nums[i]:
                    if (dp[j]+1)>dp[i]:
                        dp[i]=dp[j]+1
                        cnt[i]=cnt[j]
                    elif (dp[j]+1)==dp[i]:
                        cnt[i]+=cnt[j]
            if dp[i]>maximum:
                maximum=dp[i]
                maxLst=[i]
            elif dp[i]==maximum:
                maxLst.append(i)
        ans=sum([cnt[i] for i in maxLst])
        return ans
