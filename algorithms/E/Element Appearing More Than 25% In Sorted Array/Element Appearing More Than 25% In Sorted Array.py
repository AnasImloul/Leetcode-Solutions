class Solution:
    def findSpecialInteger(self, arr: List[int]) -> int:
        l=len(arr)
        c=(l//4)+1
        d={}
        for i in arr:
            if i in d:
                d[i]+=1
            else:
                d[i]=1
            if d[i]>=c:
                return i
