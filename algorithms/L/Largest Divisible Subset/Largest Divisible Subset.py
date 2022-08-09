class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        dp = [1 for i in range(n)]
        hashh = [i for i in range(n)]
        ans_ind = 0
        
        for i in range(1, n):
            for j in range(0,i):
                if nums[i]%nums[j] == 0 and dp[j]+1 > dp[i]:            
                    dp[i] = dp[j]+1
                    hashh[i] = j
                    
                    # print(dp)
                    # print(hashh)
        out = []
        maxi = dp[0]
        
        for i in range(len(nums)):
            if dp[i] > maxi:
                ans_ind = i
                maxi = dp[i]
        
        while(hashh[ans_ind]!=ans_ind):
            out.append(nums[ans_ind])
            ans_ind = hashh[ans_ind]
        out.append(nums[ans_ind])
        return(out)
        
        
        
