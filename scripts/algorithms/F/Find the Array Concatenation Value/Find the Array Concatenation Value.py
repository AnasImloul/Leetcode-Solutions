// Runtime: 48 ms (Top 93.88%) | Memory: 17.60 MB (Top 14.01%)

class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        i=0
        j=len(nums)-1
        res=0
        while i<=j:
            if i==j:       
                res+=int(nums[i])
            elif i!=j:
                res+=int(str(nums[i])+str(nums[j]))
            i+=1
            j-=1
        return res
