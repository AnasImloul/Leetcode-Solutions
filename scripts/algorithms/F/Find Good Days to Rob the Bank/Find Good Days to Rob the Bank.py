class Solution:
    def goodDaysToRobBank(self, nums: List[int], time: int) -> List[int]:  
        n=len(nums)
        if time==0:return range(n)
        res=[]
        p1,p2=0,0
        for i in range(1,n-time):
            p1+=1 if nums[i-1]>=nums[i] else -p1
            p2+=1 if nums[i+time-1]<=nums[i+time] else -p2
            
            if p1>=time and p2>=time:res.append(i)
        return res
