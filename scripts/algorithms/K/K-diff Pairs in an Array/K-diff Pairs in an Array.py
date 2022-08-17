class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        nums.sort()
        dict1={}
        s=0
        res=[]
        for n in nums:
            if dict1.get(n,None) is not None:
                res.append(n)
            dict1[n+k]=n
        res=list(set(res))
        return len(res)
