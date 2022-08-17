class Solution:
    class Solution:
    def largestVariance(self, s: str) -> int:
        
        def maxSubArray(nums: List[int]):
            ans=-float('inf')
            runningSum=0
            seen=False
            for x in (nums):
                if x<0:
                    seen=True
                runningSum+=x
                if seen:
                    ans=max(ans,runningSum)
                else:
                    ans=max(ans,runningSum-1)
                if runningSum<0:
                    runningSum=0
                    seen=False
            return ans
        
        f=set()
        a=''
        for x in s:
            if x not in f:
                a+=x
                f.add(x)
       
        n=len(s)
        res=0
        for j in range(len(a)-1):
            for k in range(j+1,len(a)):
                x=a[j]
                y=a[k]
                arr=[]
                for i in range(n):
                    if s[i]!=x and s[i]!=y:
                        continue
                    elif s[i]==x:
                        arr.append(1)
                    else:
                        arr.append(-1)
                
                res=max(res,maxSubArray(arr),maxSubArray([-x for x in arr]))
                
        return res
                
                
                
                

