// Runtime: 147 ms (Top 96.67%) | Memory: 19.20 MB (Top 63.7%)

class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        n=len(wage)
        arr=[[wage[i]/quality[i],quality[i]] for i in range(n)]
        arr.sort(key=lambda x:x[0])
        kSmallest=0
        pq=[]
        for i in range(k):
            heapq.heappush(pq,-arr[i][1])
            kSmallest+=arr[i][1]
        minCost=arr[k-1][0]*kSmallest
        for c in range(k,n):
            if pq and abs(pq[0])>arr[c][1]:
                qRem=-heappop(pq)
                kSmallest-=qRem
                kSmallest+=arr[c][1]
                heappush(pq,-arr[c][1])
            minCost=min(minCost,arr[c][0]*kSmallest)
        return minCost
            
        
        
