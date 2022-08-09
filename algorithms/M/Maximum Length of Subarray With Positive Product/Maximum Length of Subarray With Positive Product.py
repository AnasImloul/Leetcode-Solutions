class Solution:
    def getMaxLen(self, arr: List[int]) -> int:
        n=len(arr)
        def solve(nums):
            i,j,last_neg,neg,ans=0,0,None,0,0
            while j<n:
                while j<n and nums[j]!=0:
                    if nums[j]<0: 
                        neg+=1
                        last_neg=j
                    j+=1
                if neg%2==0:
                    ans=max(ans,j-i)
                elif last_neg!=None:
                    ans=max(ans,last_neg-i,j-last_neg-1)
                i,j,neg,last_neg=j+1,j+1,0,None
            return ans
        return max(solve(arr),solve(arr[::-1]))

        
            
            
