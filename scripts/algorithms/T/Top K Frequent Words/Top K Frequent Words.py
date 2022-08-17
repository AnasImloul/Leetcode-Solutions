import heapq
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        
        li = {}
        for i in words:
            if i in li:
                li[i]+=1
            else:
                li[i]=1
        
        heap = []
        for i in li:
            heap.append([-li[i],i])
        
        heapq.heapify(heap)
        
        ans = []
        for i in range(k):
            ans.append(heapq.heappop(heap)[1])
        
        return ans