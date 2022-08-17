class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:        
        rides.sort()
        for job in rides:
            job[2]+=job[1]-job[0]
        
        heap=[]
        cur=ans=0
        for start,e,p in rides:
            
            while heap and heap[0][0]<=start: 
                _,val=heappop(heap)
                cur=max(cur,val)
            heappush(heap,(e,cur+p))
           
            ans=max(ans,cur+p)
            
        return ans
