class Solution:
    def runningSum(self, nums):
        a=0
        list=[]
        for i in nums:
            a=i+a
            list.append(a)
        return(list)