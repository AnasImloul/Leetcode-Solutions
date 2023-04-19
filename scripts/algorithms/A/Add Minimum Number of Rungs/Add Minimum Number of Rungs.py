class Solution:
    def addRungs(self, rungs: List[int], dist: int) -> int:
        rungs=[0]+rungs
        i,ans=1,0
        while i<len(rungs): 
            if rungs[i]-rungs[i-1] > dist:
                ans+=ceil((rungs[i]-rungs[i-1])/dist)-1
            i+=1
        return ans



            