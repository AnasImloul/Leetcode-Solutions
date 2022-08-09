class Solution:
    
    def solve(self,k,target,ans,temp,idx,nums):
        
        if idx==len(nums):
            if target==0 and k==0:
                ans.append(list(temp))
            return
        
        if nums[idx]<=target:
            
            temp.append(nums[idx])
            self.solve(k-1,target-nums[idx],ans,temp,idx+1,nums)
            temp.pop()
        
        self.solve(k,target,ans,temp,idx+1,nums)
        

    
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        
        ans = []
        temp = []
        idx = 0
        nums = list(range(1,10))
        
        self.solve(k,n,ans,temp,idx,nums)
        return ans
                
