import heapq
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        
        h = {}
        for i in nums:
            if i in h:
                h[i]+=1
            else:
                h[i]=1
        
        heap = []
        for i in h:
            heap.append([i,h[i]])
        
        heapq.heapify(heap)
        ans = []
        
        while heap:
            x = heapq.heappop(heap)
            ans.append(x[0])
            if x[1]>1:
                heapq.heappush(heap,[x[0],x[1]-1])
                
        return ans
