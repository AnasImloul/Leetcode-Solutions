# Runtime: 392 ms (Top 52.0%) | Memory: 17.80 MB (Top 65.5%)

class Solution:
    p=[]
    def __init__(self):
        if(len(self.p)!=0):return
        self.s=[1 for i in range(1001)]
        for i in range(2,1001):
            if(not self.s[i]):continue
            self.p.append(i)
            for j in range(i*i,1001,i):
                self.s[j]=0
        
    def distinctPrimeFactors(self, nums: List[int]) -> int:
        # print(self.p)
        ans=0
        for i in range(len(self.p)):
            for j in range(len(nums)):
                if(nums[j]%self.p[i]==0):
                    # print(i,j,nums[j],self.p[i])
                    ans+=1
                    break
        return ans