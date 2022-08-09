 class Solution:
    def maxSizeSlices(self, slices: List[int]) -> int:
       ** #This solve function mainly on work on the idea of A Previous dp problem House Robber II 
		#If we take the first slice then we cant take the second slice and vice versa**
		def solve(slices,start,end,n,dp):
            if start>end or n==0:
                return 0
            if dp[start][n] !=-1:
                return dp[start][n]
            include = slices[start] + solve(slices,start+2,end,n-1,dp)
            
            exclude = 0 + solve(slices,start+1,end,n,dp)
            
            dp[start][n]= max(include,exclude)
            return dp[start][n]
        dp1=[[-1 for i in range(k+1)]for _ in range(k+1)]
        dp2=[[-1 for i in range(k+1)]for _ in range(k+1)]
        
        option1=solve(slices,0,k-2,k//3,dp1)#Taking the the first slice , now we cant take the last slice and next slice
        option2=solve(slices,1,k-1,k//3,dp2)#Taking the the second slice , now we cant take the second last slice and next slice
        
        return max(option1,option2)
