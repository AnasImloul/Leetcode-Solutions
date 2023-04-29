class Solution:
    def check(self, num: List[int]) -> bool:
        ct=0
        for i in range(1,len(num)):
            if num[i-1]>num[i]:
                ct+=1
        if num[len(num)-1]>num[0]:
            ct+=1
        return ct<=1